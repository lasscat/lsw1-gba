"""The one config of the LSW1 GBA decomp: every path, tool name and compiler flag the build and the matching tools use.

Nothing else hardcodes a location. The repo root is the parent of tools/ (override: $LSW1_ROOT); the workspace (job
records, local workflow) is the parent of the repo (override: $LSW1_WORKSPACE). Scripts outside the repo import this
module after adding <repo>/tools to sys.path (see `worker-records/wsconfig.py`).

    ROOT/VERSION/CONFIG      repo, config/usa
    SYMBOLS, LAYOUT          disasm inputs (address kind name; segments)
    SOURCES                  config/usa/sources.txt: the C files linked in place of asm functions
    ASM, MANIFEST            generated asm/ (ignored) and its ROM-order file list
    BUILT_ROM, ELF, MAP      ninja outputs
    CC, CC_FLAGS, CPP_ARGS   the game compiler (agbcc, phase 4) and its preprocessor
    WORKER_RECORDS, JOBS     coordinator job records (outside the repo, never in /tmp)
"""
from __future__ import annotations

import hashlib
import os
import re
import shutil
import struct
import subprocess
from pathlib import Path

TOOLS = Path(__file__).resolve().parent
ROOT = Path(os.environ.get('LSW1_ROOT') or TOOLS.parent).resolve()
WORKSPACE = Path(os.environ.get('LSW1_WORKSPACE') or ROOT.parent).resolve()

VERSION = 'usa'
CONFIG = ROOT / 'config' / VERSION
SHA1_FILE = CONFIG / 'baserom.sha1'
LAYOUT = CONFIG / 'layout.txt'
SYMBOLS = CONFIG / 'symbols.txt'
LD_SCRIPT = CONFIG / 'ld_script.ld'
SOURCES = CONFIG / 'sources.txt'
ASM_APPROVALS = ROOT / 'config' / 'asm_approvals.json'
ASM = ROOT / 'asm'
MANIFEST = ASM / 'manifest.txt'
BUILD = ROOT / 'build' / VERSION
BUILT_ROM = BUILD / f'lsw1_{VERSION}.gba'
ELF = BUILD / f'lsw1_{VERSION}.elf'
MAP = BUILD / f'lsw1_{VERSION}.map'
OBJ = BUILD / 'obj'
EXTRACT = ROOT / 'extract'
SRC = ROOT / 'src'
SRC_AUTO = SRC / 'auto'  # integrate_one.py puts accepted worker C here
INCLUDE = ROOT / 'include'
SOURCE_DIRS = (SRC, INCLUDE)  # ASCII + source policy apply here

ROM_START = 0x08000000
ROM_END = 0x09000000  # 16 MiB; objcopy pads the image to here with 0x00
GAME_CODE = (0x08000180, 0x08043C3C)  # agbcc game Thumb code (docs/rom-survey.md); libraries start at 0x080477C0

# Toolchain. Binutils come from PATH; agbcc is built into tools/agbcc by tools/setup_agbcc.sh.
BINUTILS_PREFIX = os.environ.get('LSW1_BINUTILS_PREFIX', 'arm-none-eabi-')
AS_FLAGS = ['-mcpu=arm7tdmi']
AGBCC = Path(os.environ.get('AGBCC') or TOOLS / 'agbcc' / 'bin').resolve()
CC = AGBCC / 'old_agbcc'
CC_FLAGS = ['-O2', '-mthumb-interwork', '-mtpcs-frame', '-mtpcs-leaf-frame']  # docs/compiler.md
CPP = 'clang'
CPP_ARGS = ['-E', '-x', 'c', '-undef', '-nostdinc', '-D__GNUC__=2', '-D__thumb__', '-D__arm__',
            '-I', str(AGBCC.parent / 'include'), '-I', str(INCLUDE)]

# Workspace (coordinator side; workers write only in their job's scratch/).
WORKER_RECORDS = WORKSPACE / 'lsw1-repair-checkpoint' / 'worker-records'
JOBS = WORKER_RECORDS / 'jobs'
LOCAL_WORKFLOW = WORKSPACE / 'lsw1-local-workflow'
JUDGE = TOOLS / 'judge.py'


def binutil(name: str) -> str:
    return BINUTILS_PREFIX + name


def rel(p) -> str:
    """Path relative to the repo root (what build.ninja and the records use)."""
    return str(Path(p).resolve().relative_to(ROOT))


def target_sha1() -> str:
    """The SHA1 the rebuilt ROM must have: first token of config/usa/baserom.sha1."""
    return SHA1_FILE.read_text().split()[0].lower()


def baserom_name() -> str:
    return SHA1_FILE.read_text().split()[1]


def sha1_of(path: Path) -> str:
    return hashlib.sha1(path.read_bytes()).hexdigest()


def find_baserom() -> Path:
    """The user's dump: extract/<name from baserom.sha1> if present, else the extract/*.gba with that SHA1."""
    named = EXTRACT / baserom_name()
    if named.is_file():
        return named
    want = target_sha1()
    for p in sorted(EXTRACT.glob('*.gba')):
        if p.stat().st_size == ROM_END - ROM_START and sha1_of(p) == want:
            return p
    raise SystemExit(f'no ROM with SHA1 {want} in {EXTRACT}')


# -- symbols.txt and sources.txt

def read_symbols() -> dict:
    """{address: (kind, name)} from symbols.txt (kind: thumb | arm | data)."""
    out = {}
    for line in SYMBOLS.read_text().splitlines():
        f = line.split('#', 1)[0].split()
        if len(f) == 3:
            out[int(f[0], 16)] = (f[1], f[2])
    return out


def symbol_by_name(name: str):
    """(address, kind) of a symbol, or None. Also takes a bare address (0x0800...)."""
    syms = read_symbols()
    try:
        a = int(name, 16)
        if a in syms:
            return a, syms[a][0]
    except ValueError:
        pass
    for a, (kind, n) in syms.items():
        if n == name:
            return a, kind
    return None


def segments() -> list:
    """[(name, vma, lma, size)] from layout.txt."""
    out = []
    for line in LAYOUT.read_text().splitlines():
        f = line.split('#', 1)[0].split()
        if f[:1] == ['seg']:
            out.append((f[1], int(f[2], 16), int(f[3], 16), int(f[4], 16)))
    return out


def span_ends() -> list:
    """Sorted addresses where a function's span must stop: every symbol, every segment end, and the start of every
    data/header region of layout.txt (data without symbols yet)."""
    ends = set(read_symbols())
    for line in LAYOUT.read_text().splitlines():
        f = line.split('#', 1)[0].split()
        if f[:1] == ['seg']:
            ends.add(int(f[2], 16) + int(f[4], 16))
        elif f[:1] in (['data'], ['header']):
            ends.add(int(f[1], 16))
    return sorted(ends)


def symbol_span(addr: int, ends: list | None = None) -> int:
    """Bytes from addr to the next span end (the function, its literal pool, its alignment padding)."""
    later = [e for e in (ends or span_ends()) if e > addr]
    if not later:
        raise SystemExit(f'nothing ends 0x{addr:08X}')
    return later[0] - addr


def in_segment(addr: int) -> bool:
    return any(vma <= addr < vma + size for _name, vma, _lma, size in segments())


def ram_placeholder(name: str):
    """Address of a placeholder data name gUnknown_XXXXXXXX outside every segment (RAM the asm reaches only by
    address), which integrate_one.py may add to symbols.txt as `data` (configure.py then defines it), else None."""
    m = re.fullmatch(r'gUnknown_([0-9A-F]{8})', name)
    return int(m.group(1), 16) if m and not in_segment(int(m.group(1), 16)) else None


def read_sources() -> list:
    """[(c path relative to the repo, [function names])] from sources.txt, in file order.

    Each line is `src/<file>.c name [name...]`: the functions the file defines, contiguous and in ROM order. The
    build links the object where the first function's asm was and drops those functions' asm files."""
    out = []
    if not SOURCES.is_file():
        return out
    for line in SOURCES.read_text().splitlines():
        f = line.split('#', 1)[0].split()
        if f:
            if len(f) < 2:
                raise SystemExit(f'{rel(SOURCES)}: "{line}" names no function')
            out.append((f[0], f[1:]))
    return out


def rom_bytes(addr: int, size: int) -> bytes:
    """Bytes of the original ROM at a ROM address (0x08xxxxxx)."""
    if not ROM_START <= addr < ROM_END:
        raise SystemExit(f'0x{addr:08X} is not a ROM address (IWRAM/EWRAM code needs its LMA)')
    with open(find_baserom(), 'rb') as fh:
        fh.seek(addr - ROM_START)
        return fh.read(size)


# -- compiling one C file the way the build does

# Appended to agbcc's output before assembling. agbcc pads between the functions of one file with `.align 2, 0`
# (zero halfwords); at the end of a file GAS would pad the section with a Thumb nop (0x46C0) instead.
END_PAD = '\t.align\t2, 0\n'


def compile_c(source: Path, obj: Path, timeout: int | None = None) -> subprocess.CompletedProcess:
    """clang -E -> agbcc (+ END_PAD) -> as, leaving <obj>.i and <obj>.s next to the object. Returns the failing step's result
    (or the assembler's on success); the ninja cc rule in configure.py runs the same commands."""
    obj = Path(obj)
    pre, asm = obj.with_suffix('.i'), obj.with_suffix('.s')
    steps = [[CPP, *CPP_ARGS, str(Path(source).resolve()), '-o', str(pre)],
             [str(CC), *CC_FLAGS, str(pre), '-o', str(asm)],
             [binutil('as'), *AS_FLAGS, str(asm), '-o', str(obj)]]
    r = None
    for cmd in steps:
        if cmd[0] == binutil('as'):
            with open(asm, 'a') as fh:
                fh.write(END_PAD)
        r = subprocess.run(cmd, capture_output=True, text=True, timeout=timeout)
        if r.returncode != 0:
            break
    return r


def toolchain_problems() -> list:
    probs = [f'{t} not on PATH' for t in (CPP, binutil('as'), binutil('ld'), binutil('objcopy'), binutil('objdump'))
             if shutil.which(t) is None]
    if not CC.is_file():
        probs.append(f'{CC} missing (run tools/setup_agbcc.sh)')
    return probs


# -- ELF objects (no dependency)

def elf_sections(obj: Path) -> list:
    """[(name, type, flags, offset, size)] of an ELF32 object."""
    d = Path(obj).read_bytes()
    shoff, = struct.unpack_from('<I', d, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from('<HHH', d, 0x2E)
    secs = [struct.unpack_from('<IIIIIIIIII', d, shoff + i * shentsize) for i in range(shnum)]
    names = secs[shstrndx][4]
    out = []
    for s in secs:
        end = d.index(b'\0', names + s[0])
        out.append((d[names + s[0]:end].decode(), s[1], s[2], s[4], s[5]))
    return out


def elf_symbols(obj: Path) -> list:
    """[(name, value, size, bind, type, section index)] from the symtab of an ELF32 object."""
    d = Path(obj).read_bytes()
    shoff, = struct.unpack_from('<I', d, 0x20)
    shentsize, shnum, _ = struct.unpack_from('<HHH', d, 0x2E)
    secs = [struct.unpack_from('<IIIIIIIIII', d, shoff + i * shentsize) for i in range(shnum)]
    out = []
    for s in secs:
        if s[1] != 2:  # SHT_SYMTAB
            continue
        strtab = secs[s[6]]
        for i in range(1, s[5] // 16):
            st_name, value, size, info, _other, shndx = struct.unpack_from('<IIIBBH', d, s[4] + i * 16)
            end = d.index(b'\0', strtab[4] + st_name)
            out.append((d[strtab[4] + st_name:end].decode(), value, size, info >> 4, info & 0xF, shndx))
    return out


# ARM relocation types (binutils numbering) that cover 2 bytes; every other one the game uses covers 4
# (R_ARM_ABS32 2 = data word, R_ARM_THM_CALL 10 = Thumb bl, R_ARM_CALL 28 / R_ARM_JUMP24 29, ...).
RELOC_DATA = {2: 'ABS32'}
RELOC_2BYTE = {102: 'THM_JUMP11', 103: 'THM_JUMP8'}


def elf_relocs(obj: Path, section: str = '.text') -> list:
    """[(offset, type, symbol name, size in bytes)] of the REL entries for one section of an ELF32 object. A section
    symbol (assembler-local reference) is named after its section."""
    d = Path(obj).read_bytes()
    shoff, = struct.unpack_from('<I', d, 0x20)
    shentsize, shnum, _ = struct.unpack_from('<HHH', d, 0x2E)
    secs = [struct.unpack_from('<IIIIIIIIII', d, shoff + i * shentsize) for i in range(shnum)]
    names = [s[0] for s in elf_sections(obj)]
    out = []
    for s in secs:
        if s[1] != 9 or names[s[7]] != section:  # SHT_REL for that section (sh_info)
            continue
        symtab, strtab = secs[s[6]], secs[secs[s[6]][6]]
        for i in range(s[5] // 8):
            offset, info = struct.unpack_from('<II', d, s[4] + i * 8)
            st_name, _v, _s, st_info, _o, shndx = struct.unpack_from('<IIIBBH', d, symtab[4] + (info >> 8) * 16)
            name = d[strtab[4] + st_name:d.index(b'\0', strtab[4] + st_name)].decode()
            if (st_info & 0xF) == 3:  # STT_SECTION
                name = names[shndx]
            out.append((offset, info & 0xFF, name, 2 if (info & 0xFF) in RELOC_2BYTE else 4))
    return out


def asm_object(name: str) -> Path:
    """The object ninja assembles from asm/code/<name>.s (it exists while the function is still asm)."""
    return OBJ / 'code' / f'{name}.o'


def allowed_head() -> str:
    """Preprocessor lines a candidate may use (the judge's fake-match baseline): an #include of a repo header."""
    return ''.join(f'#include "{p.relative_to(INCLUDE)}"\n' for p in sorted(INCLUDE.rglob('*.h')))
