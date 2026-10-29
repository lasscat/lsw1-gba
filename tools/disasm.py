#!/usr/bin/env python3
"""Disassembles the LSW1 GBA ROM into GNU as source under asm/ (phase 3: the all-asm rebuild).

    python tools/disasm.py discover   # finds function starts, writes config/usa/symbols.txt (run once)
    python tools/disasm.py emit       # writes asm/ from the ROM + config/usa/layout.txt + symbols.txt

config/ holds only addresses, modes and names; everything under asm/ is ROM-derived and git-ignored.

Code regions are swept linearly (ARM 4 bytes, Thumb 2 bytes, BL pairs 4). Words loaded with a pc-relative
ldr are literal pools; even pool words pointing into the same Thumb region (and ARM `ldr pc, [pc, rX, lsl #2]`)
start jump tables. Function starts: BL targets, code pointers in pools, and code after a return/branch that
nothing branches to. Every instruction text is assembled once with GNU as (`selftest`); one whose bytes differ
from the ROM is written as .inst, so the output reassembles to the ROM by construction. The proof is still
tools/verify.py on the linked ROM.
"""
import argparse
import re
import struct
import subprocess
import sys
import tempfile
from dataclasses import dataclass
from pathlib import Path

import capstone

sys.path.insert(0, str(Path(__file__).resolve().parent))
import project  # noqa: E402  (every path and flag: tools/project.py)

AS = project.binutil('as')
AS_FLAGS = project.AS_FLAGS
HEADER = '\t.syntax unified\n\t.cpu arm7tdmi\n'

# Names that are known from the survey (docs/rom-survey.md); discover writes them into symbols.txt.
KNOWN = {
    0x080000C0: '_start',
    0x08012D08: 'AgbMain',
    0x03000200: 'intr_main',
    0x08047814: 'memcpy',
    0x080479F4: 'strlen',
    0x08047A7C: '__divsi3',
    0x08047B10: '__div0',
    0x08047B14: '__modsi3',
}
NOT_STARTS = {
    0x08000140,  # crt0's closing `b _start`, after the bx to AgbMain
}
CALL_VIA = 0x08047A40  # libgcc _call_via_r0.._call_via_lr, 4 bytes each
CALL_VIA_REGS = ['r0', 'r1', 'r2', 'r3', 'r4', 'r5', 'r6', 'r7', 'r8', 'r9', 'sl', 'fp', 'ip', 'sp', 'lr']
SWI_NAMES = {  # GBATEK BIOS function names
    0x00: 'SoftReset', 0x01: 'RegisterRamReset', 0x02: 'Halt', 0x03: 'Stop', 0x04: 'IntrWait',
    0x05: 'VBlankIntrWait', 0x06: 'Div', 0x07: 'DivArm', 0x08: 'Sqrt', 0x09: 'ArcTan', 0x0A: 'ArcTan2',
    0x0B: 'CpuSet', 0x0C: 'CpuFastSet', 0x0D: 'GetBiosChecksum', 0x0E: 'BgAffineSet', 0x0F: 'ObjAffineSet',
    0x10: 'BitUnPack', 0x11: 'LZ77UnCompWram', 0x12: 'LZ77UnCompVram', 0x13: 'HuffUnComp',
    0x14: 'RLUnCompWram', 0x15: 'RLUnCompVram', 0x16: 'Diff8bitUnFilterWram', 0x17: 'Diff8bitUnFilterVram',
    0x18: 'Diff16bitUnFilter', 0x19: 'SoundBias', 0x1F: 'MidiKey2Freq',
}

COND = r'(?:eq|ne|hs|cs|lo|cc|mi|pl|vs|vc|hi|ls|ge|lt|gt|le|al)?'
RE_BRANCH = re.compile(rf'^(bl?)({COND})$')
RE_IMM = re.compile(r'^#(-?0x[0-9a-f]+|-?\d+)$')
RE_PCLDR = re.compile(r'^(r\d+|sb|sl|fp|ip|sp|lr|pc), \[pc(?:, #(-?0x[0-9a-f]+|-?\d+))?\]$')
RE_PCTABLE = re.compile(r'^pc, \[pc, (r\d+|sb|sl|fp|ip|lr), lsl #2\]$')


# ---------------------------------------------------------------------------------------------- layout


@dataclass
class Seg:
    name: str
    vma: int
    lma: int
    size: int


@dataclass
class Region:
    kind: str  # header, arm, thumb, data
    start: int
    end: int
    seg: Seg
    cont: bool = False


class Rom:
    def __init__(self, data: bytes, layout_path: Path):
        self.data = data
        self.segs: list[Seg] = []
        self.regions: list[Region] = []
        for n, line in enumerate(layout_path.read_text().splitlines(), 1):
            f = line.split('#', 1)[0].split()
            if not f:
                continue
            if f[0] == 'seg':
                self.segs.append(Seg(f[1], int(f[2], 16), int(f[3], 16), int(f[4], 16)))
                continue
            start, end = int(f[1], 16), int(f[2], 16)
            seg = self.seg_of(start)
            if f[0] not in ('header', 'arm', 'thumb', 'data') or seg is None or end > seg.vma + seg.size:
                raise SystemExit(f'{layout_path}:{n}: bad region: {line}')
            self.regions.append(Region(f[0], start, end, seg, 'cont' in f[3:]))
        for seg in self.segs:  # regions must tile each segment
            rs = [r for r in self.regions if r.seg is seg]
            at = seg.vma
            for r in rs:
                if r.start != at:
                    raise SystemExit(f'layout: gap or overlap at {at:#x} in segment {seg.name}')
                at = r.end
            if at != seg.vma + seg.size:
                raise SystemExit(f'layout: segment {seg.name} not covered to its end')

    def seg_of(self, addr):
        for s in self.segs:
            if s.vma <= addr < s.vma + s.size:
                return s
        return None

    def region_of(self, addr):
        for r in self.regions:
            if r.start <= addr < r.end:
                return r
        return None

    def off(self, addr):
        s = self.seg_of(addr)
        return s.lma - project.ROM_START + (addr - s.vma)

    def u16(self, addr):
        return struct.unpack_from('<H', self.data, self.off(addr))[0]

    def u32(self, addr):
        return struct.unpack_from('<I', self.data, self.off(addr))[0]

    def bytes(self, addr, n):
        o = self.off(addr)
        return self.data[o:o + n]


# ---------------------------------------------------------------------------------------------- decoding


@dataclass
class Item:
    addr: int
    size: int
    kind: str  # ins, bl, word, half
    mode: str  # arm, thumb
    mnem: str = ''
    ops: str = ''
    target: int = -1  # bl/b target, pool address


def imm(s):
    return int(s, 0)


class Decoder:
    def __init__(self, rom: Rom):
        self.rom = rom
        self.cs = {
            'arm': capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM),
            'thumb': capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB),
        }

    def _cs(self, mode, addr, n):
        for ins in self.cs[mode].disasm(self.rom.bytes(addr, n), addr, 1):
            if ins.size == n:
                return ins.mnemonic, ins.op_str
        return None

    def region(self, r: Region, datamap: dict) -> list:
        """Sweeps r. Literal pools ahead of the sweep are marked as they are found, so a pool word is never
        decoded as an instruction (which could mark a bogus pool of its own)."""
        datamap = dict(datamap)
        items = []
        a = r.start
        while a < r.end:
            if a in datamap:
                n = min(datamap[a], r.end - a)
                items.append(Item(a, n, 'word' if n == 4 else 'half', r.kind))
                a += n
                continue
            if r.kind == 'arm':
                if r.end - a < 4 or a % 4:
                    items.append(Item(a, 2, 'half', 'arm'))
                    a += 2
                    continue
                items.append(self._arm(a))
                a += 4
            else:
                if r.end - a < 2:
                    raise SystemExit(f'odd-sized Thumb region end at {a:#x}')
                it = self._thumb(a, r, datamap)
                items.append(it)
                a += it.size
            p = pool_addr(items[-1])
            if p is not None and a <= p < r.end and p % 4 == 0:
                datamap.setdefault(p, 4)
        return items

    def _arm(self, a):
        d = self._cs('arm', a, 4)
        if d is None:
            return Item(a, 4, 'word', 'arm')
        mnem, ops = d
        it = Item(a, 4, 'ins', 'arm', mnem, ops)
        m = RE_BRANCH.match(mnem)
        if m and RE_IMM.match(ops):
            it.kind = 'bl' if m.group(1) == 'bl' else 'ins'
            it.target = imm(ops[1:])
            if m.group(1) == 'b':
                it.kind = 'b'
        return it

    def _thumb(self, a, r, datamap):
        h = self.rom.u16(a)
        top = h >> 11
        if top == 0b11110:
            if a + 4 <= r.end and (a + 2) not in datamap:
                h2 = self.rom.u16(a + 2)
                if h2 >> 11 == 0b11111:
                    off = ((h & 0x7FF) << 12) | ((h2 & 0x7FF) << 1)
                    if off & 0x400000:
                        off -= 0x800000
                    return Item(a, 4, 'bl', 'thumb', 'bl', '', a + 4 + off)
            return Item(a, 2, 'half', 'thumb')
        if top in (0b11101, 0b11111):
            return Item(a, 2, 'half', 'thumb')
        d = self._cs('thumb', a, 2)
        if d is None:
            return Item(a, 2, 'half', 'thumb')
        mnem, ops = d
        it = Item(a, 2, 'ins', 'thumb', mnem, ops)
        m = RE_BRANCH.match(mnem)
        if m and m.group(1) == 'b' and RE_IMM.match(ops):
            it.kind = 'b'
            it.target = imm(ops[1:])
        return it


def pool_addr(it: Item):
    """Address loaded by a pc-relative ldr, or None."""
    if it.kind != 'ins' or not it.mnem.startswith('ldr') or it.mnem.startswith(('ldrb', 'ldrh', 'ldrs', 'ldrd')):
        return None
    m = RE_PCLDR.match(it.ops)
    if not m:
        return None
    off = imm(m.group(2)) if m.group(2) else 0
    if it.mode == 'thumb':
        return ((it.addr + 4) & ~3) + off
    return it.addr + 8 + off


def is_terminal(it: Item):
    """An instruction after which execution never falls through."""
    if it.kind == 'b':
        return it.mnem == 'b'
    if it.kind != 'ins':
        return False
    m, ops = it.mnem, it.ops
    if m == 'bx':
        return True
    if m == 'mov' and ops.startswith('pc,'):
        return True
    if m in ('pop', 'ldm', 'ldmia', 'ldmdb', 'ldmib', 'ldmda') and re.search(r'\bpc\}', ops):
        return True
    if it.mode == 'arm' and m == 'ldr' and ops.startswith('pc,'):
        return True
    return False


def is_padding(rom: Rom, it: Item):
    if it.mode == 'thumb':
        return it.size == 2 and rom.u16(it.addr) in (0x0000, 0x46C0)
    return it.size == 4 and rom.u32(it.addr) in (0x00000000, 0xE1A00000)


class Analysis:
    """Linear sweep of all code regions, iterated until the literal pools and jump tables are stable."""

    def __init__(self, rom: Rom):
        self.rom = rom
        self.dec = Decoder(rom)
        self.code = [r for r in rom.regions if r.kind in ('arm', 'thumb')]
        self.datamap: dict[int, int] = {}
        self.tables: dict[int, list] = {}  # table start -> entry targets
        for _ in range(20):
            self.items = []
            for r in self.code:
                self.items.extend(self.dec.region(r, self.datamap))
            self.at = {it.addr: it for it in self.items}
            if not self._find_data():
                break
        else:
            raise SystemExit('analysis did not converge')
        self.rtables = self._rodata_tables()  # GCC Thumb switch tables in ROM data

    def same_region(self, a, b):
        r = self.rom.region_of(a)
        return r is not None and r.start <= b < r.end

    def _find_data(self):
        new = {}
        for it in self.items:
            p = pool_addr(it)
            if p is not None and self.same_region(it.addr, p) and p % 4 == 0:
                new[p] = 4
            if it.mode == 'arm' and it.kind == 'ins' and it.mnem.startswith('ldr') and RE_PCTABLE.match(it.ops):
                self._table(it.addr + 8, 'arm', new)
        for p in list(new):
            v = self.rom.u32(p)
            r = self.rom.region_of(p)
            if v % 2 == 0 and r.kind == 'thumb' and r.start <= v < r.end:
                self._table(v, 'thumb', new)
        changed = new != self.datamap
        self.datamap = new
        return changed

    def _table(self, t, mode, new):
        r = self.rom.region_of(t)
        if r is None or r.kind != mode or t % 4:
            return
        entries = []
        end = r.end
        a = t
        while a + 4 <= end:
            w = self.rom.u32(a)
            if w % (4 if mode == 'arm' else 2) or not (a + 4 <= w < r.end):
                break
            entries.append(w)
            end = min(end, w)
            a += 4
        if len(entries) >= 2:
            self.tables[t] = entries
            for i in range(len(entries)):
                new[t + 4 * i] = 4

    def _rodata_tables(self):
        """GCC Thumb switch: cmp rN, #K; bhi/bls ...; lsls r0, r0, #2; ldr r1, =T; adds; ldr r0, [r0]; mov pc, r0.
        T is in ROM data and holds K+1 even case addresses in the switch's own region."""
        out = {}
        for i, it in enumerate(self.items):
            if not (it.mode == 'thumb' and it.mnem == 'mov' and it.ops.startswith('pc, r')):
                continue
            t = count = None
            for j in range(i - 1, max(i - 6, 0), -1):
                p = pool_addr(self.items[j])
                if p is not None and p in self.datamap:
                    t = self.rom.u32(p)
                    break
            for j in range(i - 1, max(i - 10, 0), -1):
                x = self.items[j]
                if x.mnem == 'cmp' and ', #' in x.ops:
                    count = imm(x.ops.split('#')[1]) + 1
                    break
            r = self.rom.region_of(t) if t is not None else None
            if r is None or r.kind != 'data' or t % 4 or count is None:
                print(f'warning: unresolved computed jump at {it.addr:#x}', file=sys.stderr)
                continue
            ents = [self.rom.u32(t + 4 * k) for k in range(count)]
            if not all(e % 2 == 0 and e in self.at and self.same_region(it.addr, e) for e in ents):
                print(f'warning: switch table {t:#x} (from {it.addr:#x}) has bad entries', file=sys.stderr)
                continue
            if t in out and out[t] != ents:
                raise SystemExit(f'switch table {t:#x} read two ways')
            out[t] = ents
        return out

    def branch_targets(self):
        out = set()
        for it in self.items:
            if it.kind == 'b':
                out.add(it.target)
        for ents in [*self.tables.values(), *self.rtables.values()]:
            out.update(ents)
        return out

    def function_starts(self):
        starts = {}
        for r in self.code:
            if not r.cont:
                starts[r.start] = r.kind
        for it in self.items:
            if it.kind == 'bl' and it.target in self.at:
                tr = self.rom.region_of(it.target)
                if tr.kind == it.mode:
                    starts[it.target] = tr.kind
            if it.kind == 'word':
                v = self.rom.u32(it.addr)
                vr = self.rom.region_of(v)
                if vr and vr.kind == 'thumb' and v % 2 and (v - 1) in self.at:
                    starts[v - 1] = 'thumb'
                elif vr and vr.kind == 'arm' and v % 4 == 0 and v in self.at and v not in self.tables:
                    starts[v] = 'arm'
        targets = self.branch_targets()
        after = False
        for it in self.items:
            if it.addr in starts:
                after = False
            if it.kind in ('word', 'half'):
                continue
            if after:
                if is_padding(self.rom, it):
                    continue
                if it.addr not in targets and not self.rom.region_of(it.addr).cont:
                    starts.setdefault(it.addr, it.mode)
            after = is_terminal(it)
        for a in NOT_STARTS:
            starts.pop(a, None)
        return starts


# ---------------------------------------------------------------------------------------------- symbols


def read_symbols(path: Path):
    """symbols.txt: `<addr> <thumb|arm|data> <name>` per line."""
    syms = {}
    for n, line in enumerate(path.read_text().splitlines(), 1):
        f = line.split('#', 1)[0].split()
        if not f:
            continue
        if len(f) != 3 or f[1] not in ('thumb', 'arm', 'data'):
            raise SystemExit(f'{path}:{n}: bad symbol line: {line}')
        syms[int(f[0], 16)] = (f[1], f[2])
    return syms


def auto_name(rom: Rom, an: Analysis, addr, mode, starts):
    if addr in KNOWN:
        return KNOWN[addr]
    if CALL_VIA <= addr < CALL_VIA + 4 * len(CALL_VIA_REGS) and (addr - CALL_VIA) % 4 == 0:
        reg = CALL_VIA_REGS[(addr - CALL_VIA) // 4]
        it = an.at.get(addr)
        if it and it.mnem == 'bx' and it.ops == reg:
            return f'_call_via_{reg}'
    it = an.at.get(addr)
    if mode == 'thumb' and it and it.mnem == 'svc':
        nxt = an.at.get(addr + 2)
        num = imm(it.ops[1:])
        if nxt and nxt.mnem == 'bx' and nxt.ops == 'lr':
            return SWI_NAMES.get(num, f'Swi{num:02X}')
        if num == 6 and nxt and (nxt.mnem, nxt.ops) == ('adds', 'r0, r1, #0'):
            return 'DivMod'
    if mode == 'thumb' and it and (it.mnem, it.ops) == ('movs', 'r2, #0'):
        nxt = an.at.get(addr + 2)
        if nxt and nxt.mnem == 'svc':
            return SWI_NAMES.get(imm(nxt.ops[1:]), 'Swi')
    # GNU ld glue: Thumb "bx pc; nop" then ARM "b target" -> <target>_from_thumb
    if mode == 'thumb' and it and (it.mnem, it.ops) == ('bx', 'pc'):
        b = an.at.get(addr + 4)
        if b and b.kind == 'b' and b.mode == 'arm':
            return f'sub_{b.target:08X}_from_thumb'
    # GNU ld long-branch stub: push {r0}; ldr r0, [pc, #8]; mov ip, r0; pop {r0}; bx ip; nop; .4byte target
    if mode == 'thumb' and it and (it.mnem, it.ops) == ('push', '{r0}'):
        ld = an.at.get(addr + 2)
        p = pool_addr(ld) if ld else None
        if p == addr + 12:
            return f'sub_{rom.u32(p):08X}_veneer'
    return f'sub_{addr:08X}'


def cmd_discover(args):
    rom = Rom(project.find_baserom().read_bytes(), project.LAYOUT)
    an = Analysis(rom)
    starts = an.function_starts()
    lines = ['# Function starts for tools/disasm.py: <address> <thumb|arm|data> <name>. Hand edits welcome',
             '# (rename, add, remove). Written by `disasm.py discover`, which overwrites this file.']
    for a in sorted(starts):
        lines.append(f'0x{a:08X} {starts[a]:5} {auto_name(rom, an, a, starts[a], starts)}')
    out = Path(args.out)
    out.write_text('\n'.join(lines) + '\n')
    nt = sum(1 for m in starts.values() if m == 'thumb')
    print(f'{out}: {len(starts)} functions ({nt} Thumb, {len(starts) - nt} ARM), '
          f'{len(an.datamap)} pool/table words, {len(an.tables)} code + {len(an.rtables)} rodata jump tables')


# ---------------------------------------------------------------------------------------------- selftest


def selftest(mode, texts):
    """{text: bytes} for each instruction text GNU as accepts; texts it rejects are left out."""
    texts = sorted(set(texts))
    result = {}
    with tempfile.TemporaryDirectory() as tmp:
        src, obj, binf = Path(tmp, 't.s'), Path(tmp, 't.o'), Path(tmp, 't.bin')
        pending = texts
        while pending:
            body = HEADER + f'\t.text\n\t.{mode}\n'  # 4 lines, so line 5 is text 0
            lines = [f't{i}: {t}' for i, t in enumerate(pending)]
            src.write_text(body + '\n'.join(lines) + f'\nt{len(pending)}:\n')
            p = subprocess.run([AS, *AS_FLAGS, '-o', str(obj), str(src)], capture_output=True, text=True)
            bad = set()
            for m in re.finditer(r't\.s:(\d+): Error', p.stderr):
                bad.add(int(m.group(1)) - 5)
            if p.returncode and not bad:
                raise SystemExit('selftest: as failed:\n' + p.stderr[:2000])
            if bad:
                pending = [t for i, t in enumerate(pending) if i not in bad]
                continue
            nm = subprocess.run(['arm-none-eabi-nm', str(obj)], capture_output=True, text=True, check=True).stdout
            addrs = {}
            for line in nm.splitlines():
                f = line.split()
                if len(f) == 3 and re.fullmatch(r't\d+', f[2]):
                    addrs[int(f[2][1:])] = int(f[0], 16)
            subprocess.run(['arm-none-eabi-objcopy', '-O', 'binary', '-j', '.text', str(obj), str(binf)],
                           check=True)
            code = binf.read_bytes()
            for i, t in enumerate(pending):
                result[t] = code[addrs[i]:addrs[i + 1]]
            break
    return result


# ---------------------------------------------------------------------------------------------- emit


class Emitter:
    def __init__(self, rom: Rom, an: Analysis, syms: dict, out: Path):
        self.rom, self.an, self.out = rom, an, out
        self.funcs = {a: v for a, v in syms.items() if v[0] != 'data'}
        self.data_names = {a: v[1] for a, v in syms.items() if v[0] == 'data'}
        for a, (mode, name) in self.funcs.items():
            r = rom.region_of(a)
            if r is None or r.kind != mode:
                raise SystemExit(f'symbols: {name} at {a:#x} is not in a {mode} region')
            if a not in an.at:
                raise SystemExit(f'symbols: {name} at {a:#x} is not at an instruction boundary')

    def run(self):
        rom, an = self.rom, self.an
        self.labels = {}  # addr -> name, for every address something refers to
        self.refs = {}  # addr -> set of files that refer to it
        self.word_text = {}  # pool/table word addr -> operand text
        self.aliases = {}  # Thumb function start -> plain label, for references without the Thumb bit
        files = self.plan_files()
        self.file_of = {}
        for f in files:
            for a in range(f['start'], f['end'], 2):
                self.file_of[a] = f['name']
        # label every referenced address
        for a, (_, name) in self.funcs.items():
            self.labels[a] = name
        for it in an.items:
            if it.kind in ('b', 'bl') and it.target in an.at:
                self.ref(it.target, it.addr, code=True)
        for t, ents in [*an.tables.items(), *an.rtables.items()]:
            for e in ents:
                self.ref(e, t, code=True)
        for t in an.rtables:
            self.ref(t, t, code=False)
        for ents in an.rtables.values():
            for e in ents:
                self.alias(e)
        for it in an.items:
            if it.kind == 'word':
                self.word_text[it.addr] = self.pool_word(it)
        # selftest all plain instruction texts
        texts = {'arm': set(), 'thumb': set()}
        for it in an.items:
            if it.kind == 'ins':
                texts[it.mode].add(self.plain(it))
        self.ok = {m: selftest(m, t) for m, t in texts.items()}
        self.fallbacks = 0
        out = self.out
        (out / 'code').mkdir(parents=True, exist_ok=True)
        (out / 'data').mkdir(exist_ok=True)
        (out / 'bin').mkdir(exist_ok=True)
        write_if_changed(out / 'macros.inc', MACROS)
        manifest = []
        for f in files:
            path = Path(f['dir'], f['name'] + '.s')
            text = self.code_file(f) if f['kind'] in ('arm', 'thumb') else self.data_file(f)
            write_if_changed(out / path, text)
            manifest.append(f"{f['seg']} {path}")
        write_if_changed(out / 'manifest.txt', '\n'.join(manifest) + '\n')
        # drop files a previous run wrote for functions or regions that no longer exist
        keep = {out / Path(m.split(None, 1)[1]) for m in manifest}
        keep |= {out / 'bin' / f'{f["name"]}.bin' for f in files if f['kind'] not in ('arm', 'thumb')}
        for d, ext in (('code', '.s'), ('data', '.s'), ('bin', '.bin')):
            for stale in (out / d).glob('*' + ext):
                if stale not in keep:
                    stale.unlink()
        # tail of the ROM after the last segment: must be the 0x00 fill objcopy writes
        end = max(s.lma + s.size for s in rom.segs) - project.ROM_START
        if rom.data[end:].strip(b'\0'):
            raise SystemExit(f'ROM tail after {end + project.ROM_START:#x} is not all 0x00')
        nfun = sum(1 for f in files if f['kind'] in ('arm', 'thumb'))
        print(f'{out}: {len(files)} files ({nfun} code), {self.fallbacks} instructions as .inst')

    # -- planning

    def plan_files(self):
        """One file per function; one per data region. A function ends at the next start or region of another kind."""
        files = []
        regions = self.rom.regions
        starts = sorted(self.funcs)
        for i, r in enumerate(regions):
            seg = r.seg.name
            if r.kind == 'header':
                files.append(dict(kind='header', start=r.start, end=r.end, seg=seg, dir='', name='rom_header'))
            elif r.kind == 'data':
                files.append(dict(kind='data', start=r.start, end=r.end, seg=seg, dir='data',
                                  name=f'data_{r.start:08X}', region=r))
            else:
                if r.cont:
                    files[-1]['end'] = r.end
                    continue
                inside = [a for a in starts if r.start <= a < r.end]
                if not inside or inside[0] != r.start:
                    raise SystemExit(f'region {r.start:#x} does not start with a function')
                for j, a in enumerate(inside):
                    e = inside[j + 1] if j + 1 < len(inside) else r.end
                    files.append(dict(kind=r.kind, start=a, end=e, seg=seg, dir='code', name=self.funcs[a][1]))
        for f in files:
            if f['kind'] == 'header':
                f['dir'] = '.'
        return files

    def ref(self, target, frm, code):
        if target not in self.labels:
            if code:
                self.labels[target] = f'_{target:08X}'
            else:
                self.labels[target] = self.data_names.get(target, f'gUnknown_{target:08X}')
        self.refs.setdefault(target, set()).add(frm)

    def alias(self, a):
        """Name for a reference to a without the Thumb bit. ld sets bit 0 of every R_ARM_ABS32 to a Thumb %function
        symbol, so an even word pointing at a Thumb function start (a switch case that is also a function start)
        uses a plain label placed at the same address."""
        if a in self.funcs and self.funcs[a][0] == 'thumb':
            self.aliases.setdefault(a, f'_{a:08X}')
            return self.aliases[a]
        return self.labels[a]

    def data_label_ok(self, v):
        r = self.rom.region_of(v)
        return r is not None and r.kind == 'data'

    def pool_word(self, it):
        """Operand text for a data word inside code: a symbol when it points at something we label."""
        v = self.rom.u32(it.addr)
        an = self.an
        r = self.rom.region_of(v & ~1)
        if r is None:
            return f'0x{v:08X}'
        if r.kind == 'data':
            for t, ents in an.rtables.items():  # e.g. GCC's folded &arr[-1] when arr follows a switch table
                if t < v < t + 4 * len(ents):
                    self.ref(t, it.addr, code=False)
                    return f'{self.labels[t]} + 0x{v - t:X}'
            self.ref(v, it.addr, code=False)
            return self.labels[v]
        if r.kind == 'thumb':
            base = v & ~1
            if base in an.at and an.at[base].mode == 'thumb':
                if base in self.funcs:
                    self.ref(base, it.addr, code=True)
                    if v % 2:  # ld sets the Thumb bit of a %function symbol
                        return self.labels[base]
                    return self.alias(base)
                self.ref(base, it.addr, code=True)
                return self.labels[base] + (' + 1' if v % 2 else '')
            return f'0x{v:08X}'
        if r.kind == 'arm' and v % 4 == 0 and v in an.at:
            self.ref(v, it.addr, code=True)
            return self.labels[v]
        return f'0x{v:08X}'

    # -- code

    def plain(self, it):
        return f'{it.mnem} {it.ops}'.strip()

    def target_ok(self, it):
        """A b/bl can use a label if its target is labelled code of the right mode."""
        t = self.an.at.get(it.target)
        if t is None or it.target not in self.labels:
            return False
        if it.kind == 'bl' or it.mode == 'arm':
            return t.mode == it.mode
        return t.mode == 'thumb'

    def ins_text(self, it):
        if it.kind in ('b', 'bl') and self.target_ok(it):
            return f'{it.mnem} {self.labels[it.target]}'
        if it.kind == 'bl':
            self.fallbacks += 1
            if it.mode == 'arm':
                return f'.inst 0x{self.rom.u32(it.addr):08X} @ {self.plain(it)}'
            b = self.rom.bytes(it.addr, 4)
            return f'.inst.n 0x{b[0] | b[1] << 8:04X}, 0x{b[2] | b[3] << 8:04X}'
        text = self.plain(it)
        want = self.rom.bytes(it.addr, it.size)
        if self.ok[it.mode].get(text) != want:
            self.fallbacks += 1
            if it.mode == 'thumb':
                return f'.inst.n 0x{self.rom.u16(it.addr):04X} @ {text}'
            return f'.inst 0x{self.rom.u32(it.addr):08X} @ {text}'
        p = pool_addr(it)
        if p is not None and p in self.word_text:
            text += f' @ ={self.word_text[p]}'
        return text

    def code_file(self, f):
        an = self.an
        lines = [HEADER.rstrip('\n'), '\t.include "macros.inc"']
        sect = '\t.text' if f['seg'] == 'rom' else f'\t.section .{f["seg"]},"ax",%progbits'
        lines += [sect, '']
        name = self.funcs[f['start']][1]
        mode = None
        a = f['start']
        while a < f['end']:
            it = an.at.get(a)
            if it is None:  # inside an item that started earlier: cannot happen with a correct plan
                raise SystemExit(f'{f["name"]}: no item at {a:#x}')
            if it.mode != mode:
                mode = it.mode
                if a != f['start']:
                    lines.append(f'\t.{mode}')
            if a == f['start']:
                lines.append(f'\t{mode}_func_start {name}')
                lines.append(f'{name}: @ 0x{a:08X}')
                if a in self.aliases:
                    lines.append(f'\t.global {self.aliases[a]}')
                    lines.append(f'{self.aliases[a]}:')
            elif a in self.labels:
                lab = self.labels[a]
                if a in self.funcs:
                    raise SystemExit(f'function {lab} inside {name}')
                if any(self.file_of.get(r) != f['name'] for r in self.refs.get(a, ())):
                    lines.append(f'\t.global {lab}')
                lines.append(f'{lab}:')
            if a + it.size == f['end'] and it.mode == 'thumb' and it.size == 2 and self.rom.u16(a) == 0:
                # A trailing zero halfword is agbcc's END_PAD, which sits after the compiler's .size: keep it out
                # of the symbol too, so objdiff sizes the asm and C functions alike. Bytes are unchanged.
                lines.append(f'\tfunc_end {name}')
                name = None
            nxt = an.at.get(a + it.size)
            if it.mode == 'thumb' and it.size == 2 and self.rom.u16(a) == 0 and nxt is not None and nxt.kind == 'word':
                lines.append('\t.2byte 0x0000')  # agbcc's `.align 2, 0` before a literal pool: data, as in its objects
            elif it.kind == 'word':
                lines.append(f'\t.4byte {self.word_text[a]}')
            elif it.kind == 'half':
                lines.append(f'\t.2byte 0x{self.rom.u16(a):04X}')
            else:
                lines.append('\t' + self.ins_text(it))
            a += it.size
        if a != f['end']:
            raise SystemExit(f'{f["name"]}: last item overruns {f["end"]:#x}')
        if name:
            lines.append(f'\tfunc_end {name}')
        return '\n'.join(lines) + '\n'

    # -- data

    def data_file(self, f):
        rom = self.rom
        binname = f'bin/{f["name"]}.bin'
        if f['kind'] == 'header':
            binname = 'bin/rom_header.bin'
        write_if_changed(self.out / binname, rom.bytes(f['start'], f['end'] - f['start']), binary=True)
        lines = [HEADER.rstrip('\n')]
        if f['seg'] == 'rom':
            lines.append('\t.text')
        elif f['seg'] == 'iwram':
            lines.append('\t.section .iwram,"ax",%progbits')
        else:
            lines.append('\t.section .ewram,"aw",%progbits')
        lines.append('')
        if f['kind'] == 'header':
            # entry branch, then the rest of the cartridge header as bytes
            lines += ['\t.arm', '\tb _start', f'\t.incbin "{binname}", 4']
            return '\n'.join(lines) + '\n'
        tables = {t: ents for t, ents in self.an.rtables.items() if f['start'] <= t < f['end']}
        ends = {t + 4 * len(ents) for t, ents in tables.items()} - {f['end']}
        cuts = sorted({f['start']} | ends | {a for a in self.labels if f['start'] <= a < f['end']})
        for i, a in enumerate(cuts):
            e = cuts[i + 1] if i + 1 < len(cuts) else f['end']
            if a in self.labels:
                lab = self.labels[a]
                lines.append(f'\t.global {lab}')
                lines.append(f'{lab}: @ 0x{a:08X}')
            if a in tables:  # switch table: one case label per word
                if e != a + 4 * len(tables[a]):
                    raise SystemExit(f'label inside switch table {a:#x}')
                lines += [f'\t.4byte {self.alias(x)}' for x in tables[a]]
            else:
                lines.append(f'\t.incbin "{binname}", 0x{a - f["start"]:X}, 0x{e - a:X}')
        return '\n'.join(lines) + '\n'


MACROS = """\
@ Generated by tools/disasm.py.
	.macro thumb_func_start name
	.thumb
	.global \\name
	.type \\name, %function
	.thumb_func
	.endm

	.macro arm_func_start name
	.arm
	.global \\name
	.type \\name, %function
	.endm

	.macro func_end name
	.size \\name, .-\\name
	.endm
"""


def write_if_changed(path: Path, content, binary=False):
    """Keeps timestamps (and ninja's work) when a regenerated file is unchanged."""
    path.parent.mkdir(parents=True, exist_ok=True)
    data = content if binary else content.encode('ascii')
    if path.is_file() and path.read_bytes() == data:
        return
    path.write_bytes(data)


def cmd_emit(args):
    rom = Rom(project.find_baserom().read_bytes(), project.LAYOUT)
    an = Analysis(rom)
    Emitter(rom, an, read_symbols(project.SYMBOLS), Path(args.out)).run()


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n\n')[0])
    sub = ap.add_subparsers(dest='cmd', required=True)
    d = sub.add_parser('discover', help='find function starts, write symbols.txt')
    d.add_argument('--out', default=str(project.SYMBOLS))
    e = sub.add_parser('emit', help='write the asm/ tree')
    e.add_argument('--out', default=str(project.ASM))
    args = ap.parse_args()
    {'discover': cmd_discover, 'emit': cmd_emit}[args.cmd](args)


if __name__ == '__main__':
    main()
