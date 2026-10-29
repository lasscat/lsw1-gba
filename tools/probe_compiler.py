#!/usr/bin/env python3
"""Compiler probe: compiles a C file with each agbcc build under candidate flag sets and compares
one Thumb function against the original bytes of the game.

`bl` targets and literal pool words (relocated addresses) are masked, so only the
instructions themselves have to match. A MATCH here is a lead, not proof: only `ninja verify`
(ROM SHA1) proves a match.

Pipeline: clang -E (preprocessor only, agbcc headers) -> agbcc (cc1, writes asm) ->
arm-none-eabi-as -mcpu=arm7tdmi -> function bytes from the ELF symtab.

Usage:
    python tools/probe_compiler.py tools/probes/phase4.c sub_08000494 0x08000494
    python tools/probe_compiler.py FILE.c FUNCTION ADDRESS [SIZE] --flags="-O2 -mthumb-interwork" --only agbcc --show

Compilers are taken from --agbcc DIR, else $AGBCC, else tools/agbcc/bin (tools/setup_agbcc.sh builds them).
"""

import argparse
import shutil
import struct
import subprocess
import tempfile
from pathlib import Path

import sys  # noqa: E402
sys.path.insert(0, str(Path(__file__).resolve().parent))
import project  # noqa: E402  (every path and flag: tools/project.py)

ROOT = project.ROOT
SYMBOLS = project.SYMBOLS

# The game's prologue/epilogue (docs/rom-survey.md) needs the backtrace frame on leaves too.
GAME_FLAGS = " ".join(f for f in project.CC_FLAGS if f != "-O2")
DEFAULT_FLAG_SETS = [f"-O2 {GAME_FLAGS}", f"-O1 {GAME_FLAGS}", f"-O2 {GAME_FLAGS} -fprologue-bugfix",
                     "-O2 -mthumb-interwork -mtpcs-frame"]
COMPILERS = ["agbcc", "old_agbcc"]


def target_bytes(addr: int, size: int) -> bytes:
    data = project.find_baserom().read_bytes()
    return data[addr - project.ROM_START: addr - project.ROM_START + size]


def symbol_size(addr: int) -> int:
    """Distance to the next symbol in symbols.txt (includes the literal pool and alignment padding)."""
    starts = []
    for line in SYMBOLS.read_text().splitlines():
        if line.strip() and not line.startswith("#"):
            starts.append(int(line.split()[0], 16))
    if addr not in starts:
        raise SystemExit(f"0x{addr:08X} is not a symbol in symbols.txt, pass the size as an argument")
    later = [a for a in starts if a > addr]
    if not later:
        raise SystemExit(f"No symbol after 0x{addr:08X}, pass the size as an argument")
    return min(later) - addr


def compiled_function(obj: Path, name: str) -> bytes | None:
    """Extracts a function's bytes from an ELF object (no external dependency)."""
    d = obj.read_bytes()
    shoff, = struct.unpack_from("<I", d, 0x20)
    shentsize, shnum, _shstrndx = struct.unpack_from("<HHH", d, 0x2E)
    secs = [struct.unpack_from("<IIIIIIIIII", d, shoff + i * shentsize) for i in range(shnum)]
    for s in secs:
        if s[1] != 2:  # SHT_SYMTAB
            continue
        strtab = secs[s[6]]
        for i in range(s[5] // 16):
            st_name, st_value, st_size, _info, _other, st_shndx = struct.unpack_from("<IIIBBH", d, s[4] + i * 16)
            end = d.index(b"\0", strtab[4] + st_name)
            if d[strtab[4] + st_name:end].decode() == name:
                sec = secs[st_shndx]
                start = st_value & ~1  # Thumb function symbols have bit 0 set
                return d[sec[4] + start: sec[4] + start + st_size]
    return None


def compare_thumb(target: bytes, cand: bytes, addr: int = 0) -> tuple[int, int]:
    """(differing halfwords, total) for Thumb code. Masks the literal pool (ldr rX,[pc,#imm] targets) and the two
    halfwords of bl/blx (the linker fills the offset)."""
    n = len(target) // 2
    if len(cand) != len(target):
        return (n, n)
    tw = struct.unpack(f"<{n}H", target)
    cw = struct.unpack(f"<{n}H", cand)
    pool = set()
    for i, w in enumerate(tw):
        if (w & 0xF800) == 0x4800:  # ldr rX, [pc, #imm8*4]
            word = ((addr + i * 2 + 4) & ~3) + (w & 0xFF) * 4 - addr
            pool.add(word // 2)
            pool.add(word // 2 + 1)
    bad = 0
    for i, (a, b) in enumerate(zip(tw, cw)):
        if i in pool:
            continue
        if (a & 0xF800) in (0xF000, 0xF800, 0xE800) and (b & 0xF800) in (0xF000, 0xF800, 0xE800):
            continue  # bl / blx halves (the linker turns bl into blx for an ARM callee)
        if a != b:
            bad += 1
    return bad, n


def trim_padding(target: bytes, cand: bytes) -> bytes:
    """symbols.txt sizes run to the next symbol, so they include the 0-2 zero bytes of alignment padding
    the compiled symbol does not have."""
    extra = target[len(cand):]
    if len(target) > len(cand) and len(extra) < 4 and not any(extra):
        return target[:len(cand)]
    return target


def disasm(code: bytes, addr: int) -> list[str]:
    objdump = shutil.which("arm-none-eabi-objdump")
    if objdump is None:
        return ["(arm-none-eabi-objdump not found in PATH)"]
    with tempfile.TemporaryDirectory() as tmp:
        f = Path(tmp) / "code.bin"
        f.write_bytes(code)
        r = subprocess.run([objdump, "-D", "-b", "binary", "-marm", "-Mforce-thumb", f"--adjust-vma={addr}", str(f)],
                           capture_output=True, text=True)
    out = []
    for line in r.stdout.splitlines():
        parts = line.split("\t")
        if len(parts) >= 3 and parts[0].strip().endswith(":"):
            out.append(" ".join(parts[2:]).split(";")[0].split("@")[0].strip())
    return out


def show(target: bytes, cand: bytes, addr: int):
    t, c = disasm(target, addr), disasm(cand, addr)
    print(f"     {'TARGET':38} | CANDIDATE")
    for i in range(max(len(t), len(c))):
        a = t[i] if i < len(t) else ""
        b = c[i] if i < len(c) else ""
        print(f"   {' ' if a == b else '*'} {a:38} | {b}")


def run(cmd: list[str], **kw) -> subprocess.CompletedProcess:
    return subprocess.run(cmd, capture_output=True, text=True, **kw)


def main():
    ap = argparse.ArgumentParser(description="Compile a function with each agbcc build and compare it to the game")
    ap.add_argument("source", type=Path)
    ap.add_argument("function")
    ap.add_argument("address", type=lambda x: int(x, 0))
    ap.add_argument("size", type=lambda x: int(x, 0), nargs="?", help="Function size (default: up to the next symbol in symbols.txt)")
    ap.add_argument("--flags", action="append", help='Flag set to test, repeatable (write --flags="-O2 -mthumb-interwork")')
    ap.add_argument("--only", choices=COMPILERS, help="Only test this compiler")
    ap.add_argument("--show", action="store_true", help="Print target/candidate disassembly side by side")
    ap.add_argument("--agbcc", type=Path, help="Directory with the agbcc binaries")
    args = ap.parse_args()

    bindir = args.agbcc or project.AGBCC
    include = bindir.parent / "include"
    for tool in ("clang", "arm-none-eabi-as"):
        if shutil.which(tool) is None:
            raise SystemExit(f"{tool} not found in PATH")
    if args.size is None:
        args.size = symbol_size(args.address)
    flag_sets = args.flags or DEFAULT_FLAG_SETS
    target_full = target_bytes(args.address, args.size)
    compilers = [c for c in COMPILERS if (bindir / c).is_file() and (args.only is None or c == args.only)]
    if not compilers:
        raise SystemExit(f"No agbcc found in {bindir} (run tools/setup_agbcc.sh)")

    with tempfile.TemporaryDirectory() as tmp:
        pre = Path(tmp) / "probe.i"
        r = run(["clang", "-E", "-x", "c", "-undef", "-nostdinc", "-D__GNUC__=2", "-D__thumb__", "-D__arm__",
                 "-I", str(include), "-I", str(ROOT / "include"), str(args.source.resolve()), "-o", str(pre)])
        if r.returncode != 0:
            raise SystemExit("preprocessor failed:\n" + r.stderr)
        for cc in compilers:
            row = []
            for flags in flag_sets:
                asm, obj = Path(tmp) / "probe.s", Path(tmp) / "probe.o"
                asm.unlink(missing_ok=True)
                obj.unlink(missing_ok=True)
                r = run([str(bindir / cc), *flags.split(), str(pre), "-o", str(asm)])
                if r.returncode == 0:
                    r = run(["arm-none-eabi-as", "-mcpu=arm7tdmi", str(asm), "-o", str(obj)])
                if r.returncode != 0 or not obj.exists():
                    if args.show:
                        print("\n".join((r.stdout + r.stderr).strip().splitlines()[:12]))
                    row.append(f"{flags}: compile error")
                    continue
                cand = compiled_function(obj, args.function)
                if cand is None:
                    row.append(f"{flags}: function not found")
                    continue
                target = trim_padding(target_full, cand)
                bad, n = compare_thumb(target, cand, args.address)
                if args.show:
                    print(f"-- {cc} {flags}")
                    show(target, cand, args.address)
                tag = "MATCH" if bad == 0 else f"{bad}/{n} diff" + ("" if len(cand) == len(target) else f" (size 0x{len(cand):x})")
                row.append(f"{flags}: {tag}")
            print(f"{cc:10} | " + "\n           | ".join(row))


if __name__ == "__main__":
    main()
