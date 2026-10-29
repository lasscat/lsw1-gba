#!/usr/bin/env python3
"""Decompilation helper: progress, worklist, single-function checks and the strict gate.

    python tools/match.py status              # functions in C vs asm (game code and libraries)
    python tools/match.py worklist [-n 20]    # smallest game functions still in asm
    python tools/match.py progress            # rewrite the progress section of README.md (no build needed)
    python tools/match.py check FUNCTION      # rebuild, compare the function's bytes in the built ROM (--diff)
    python tools/match.py verify              # strict gate: ROM SHA1 (tools/verify.py), source policy, ASCII,
                                              #   sources.txt consistency

`check` is a lead, not proof: only `verify` (the unchanged tools/verify.py printing VERIFY PASSED) proves a match.
`verify` exits non-zero on any failure; nothing is committed unless it passes. Paths and flags: tools/project.py.
"""

import argparse
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import project  # noqa: E402  (every path and flag: tools/project.py)

ROOT = project.ROOT


def run(cmd: list[str], quiet: bool = True) -> subprocess.CompletedProcess:
    return subprocess.run(cmd, cwd=ROOT, capture_output=quiet, text=True)


def c_functions() -> dict:
    """{function name: C path} from sources.txt."""
    return {name: c for c, names in project.read_sources() for name in names}


def functions() -> list:
    """[(address, kind, name, span)] of every code symbol, address order (span: project.symbol_span)."""
    ends = project.span_ends()
    return [(a, kind, name, project.symbol_span(a, ends))
            for a, (kind, name) in sorted(project.read_symbols().items()) if kind != 'data']


def is_game(addr: int) -> bool:
    return project.GAME_CODE[0] <= addr < project.GAME_CODE[1]


def cmd_status(args):
    in_c = c_functions()
    for label, pick in (('game code', is_game), ('libraries/other', lambda a: not is_game(a))):
        fs = [f for f in functions() if pick(f[0])]
        done = [f for f in fs if f[2] in in_c]
        size, done_size = sum(f[3] for f in fs), sum(f[3] for f in done)
        print(f'{label:16} {len(done):5}/{len(fs):<5} functions in C  '
              f'{done_size:#9x}/{size:#x} bytes ({100.0 * done_size / max(size, 1):.2f}%)')


def bar(percent: float, width: int = 20) -> str:
    full = round(percent / 100 * width)
    return '`' + '\u2588' * full + '\u2591' * (width - full) + '`'


def cmd_progress(args):
    """Writes the README.md block between the progress markers (created before the first code block or second-level
    title when missing). Counts come from sources.txt and symbols.txt, so no build is needed."""
    import datetime
    import re
    in_c = c_functions()
    rows = []
    for label, pick in (('Game code', is_game), ('Libraries (SDK, libgcc, Krawall)', lambda a: not is_game(a))):
        fs = [f for f in functions() if pick(f[0])]
        done = [f for f in fs if f[2] in in_c]
        rows.append((label, len(done), len(fs), sum(f[3] for f in done), sum(f[3] for f in fs)))
    _, game_done, game_total, game_bytes, game_size = rows[0]
    game = 100.0 * game_bytes / max(game_size, 1)
    lines = ['<!-- progress:start -->',
             f'{bar(game)} **{game:.2f}%** of the game code matched in C \u00b7 {game_done}/{game_total} game functions',
             '',
             '| Part of the code | Functions in C | Bytes in C | Share |',
             '|---|---|---|---|']
    for label, done, total, done_bytes, size in rows:
        lines.append(f'| {label} | {done}/{total} | {done_bytes:#x}/{size:#x} | {100.0 * done_bytes / max(size, 1):.2f}% |')
    lines += ['',
              f'*Updated {datetime.date.today().isoformat()} by `python tools/match.py progress`. A function counts only '
              f'when it compiles to the exact same bytes and the ROM still rebuilds byte for byte.*',
              '<!-- progress:end -->']
    block = '\n'.join(lines)
    readme = ROOT / 'README.md'
    text = readme.read_text(encoding='utf-8')
    if '<!-- progress:start -->' in text:
        new = re.sub(r'<!-- progress:start -->.*?<!-- progress:end -->', lambda _m: block, text, flags=re.S)
    else:
        m = re.search(r'^(```|## )', text, re.M)
        at = m.start() if m else len(text)
        new = text[:at].rstrip('\n') + '\n\n## Progress\n\n' + block + '\n\n' + text[at:]
    readme.write_text(new, encoding='utf-8', newline='\n')
    print(f'README.md progress updated: {game:.2f}% of game code, {game_done}/{game_total} game functions')


def cmd_worklist(args):
    in_c = c_functions()
    todo = sorted((f for f in functions() if is_game(f[0]) and f[2] not in in_c), key=lambda f: (f[3], f[0]))
    for a, kind, name, span in todo[:args.n]:
        print(f'{name:24} 0x{a:08X} {kind:5} {span:#6x}')


def built_bytes(addr: int, size: int) -> bytes:
    with open(project.BUILT_ROM, 'rb') as fh:
        fh.seek(addr - project.ROM_START)
        return fh.read(size)


def cmd_check(args):
    found = project.symbol_by_name(args.function)
    if found is None or found[1] == 'data':
        raise SystemExit(f'{args.function} is not a function of {project.rel(project.SYMBOLS)}')
    addr, kind = found
    name = project.read_symbols()[addr][1]
    src = c_functions().get(name)
    if src is None:
        raise SystemExit(f'{name} is still asm: list its C file in {project.rel(project.SOURCES)} first')
    r = run(['ninja', project.rel(project.BUILT_ROM)])
    if r.returncode != 0:
        print((r.stdout + r.stderr)[-4000:])
        raise SystemExit('ninja failed (compile or link error?)')
    span = project.symbol_span(addr)
    target, built = project.rom_bytes(addr, span), built_bytes(addr, span)
    diffs = sum(1 for x, y in zip(target, built) if x != y)
    print(f'{name}: {"MATCH (a lead; match.py verify is the proof)" if diffs == 0 else f"{diffs}/{span} bytes differ"}'
          f'  (0x{addr:08X}, {span:#x} bytes, {src})')
    if args.diff and diffs:
        import probe_compiler
        probe_compiler.show(target, built, addr)
    sys.exit(0 if diffs == 0 else 1)


def non_ascii_files() -> list[str]:
    bad = []
    for d in (*project.SOURCE_DIRS, project.TOOLS / 'probes'):
        for f in d.rglob('*'):
            if f.suffix in ('.c', '.h') and any(b > 0x7F for b in f.read_bytes()):
                bad.append(project.rel(f))
    if project.SOURCES.is_file() and any(b > 0x7F for b in project.SOURCES.read_bytes()):
        bad.append(project.rel(project.SOURCES))
    return bad


def sources_problems() -> list[str]:
    """Every src/ C file is linked (listed in sources.txt), and each object defines exactly its listed functions."""
    probs = []
    listed = {c for c, _ in project.read_sources()}
    for f in sorted(project.SRC.rglob('*.c')):
        if project.rel(f) not in listed:
            probs.append(f'{project.rel(f)} is not in {project.rel(project.SOURCES)} (it would never be built)')
    for c, names in project.read_sources():
        obj = project.OBJ / 'c' / Path(c).with_suffix('.o')
        if not obj.is_file():
            probs.append(f'{c}: object {project.rel(obj)} missing')
            continue
        funcs = {s[0] for s in project.elf_symbols(obj) if s[4] == 2 and s[3] == 1 and s[5] != 0}  # global FUNC
        if funcs != set(names):
            probs.append(f'{c} defines {sorted(funcs)}, sources.txt lists {names}')
    return probs


def cmd_verify(args):
    ok = True
    r = run(['ninja', 'verify'])
    out = (r.stdout or '') + (r.stderr or '')
    if r.returncode != 0 or 'VERIFY PASSED' not in out.splitlines():
        print('\n'.join(line for line in out.splitlines() if 'section alignment' not in line
                        and 'Assembler messages' not in line)[-4000:])
        print('FAIL: tools/verify.py did not print VERIFY PASSED (built ROM SHA1 != config/usa/baserom.sha1)')
        ok = False
    else:
        print(f'OK  : ROM SHA1 equals {project.target_sha1()} (tools/verify.py: VERIFY PASSED)')
    r = run([sys.executable, 'tools/check_source_policy.py'])
    if r.returncode != 0:
        print(r.stdout + r.stderr, end='')
        print('FAIL: source policy')
        ok = False
    else:
        print('OK  : source policy (no unapproved asm in changed sources)')
    bad = non_ascii_files()
    if bad:
        print('FAIL: non-ASCII characters in ' + ', '.join(bad))
        ok = False
    for p in sources_problems():
        print('FAIL: ' + p)
        ok = False
    in_c = c_functions()
    game = [f for f in functions() if is_game(f[0])]
    print(f'INFO: {len(in_c)} function(s) in C ({sum(1 for f in game if f[2] in in_c)}/{len(game)} game functions)')
    print('VERIFY PASSED' if ok else 'VERIFY FAILED')
    sys.exit(0 if ok else 1)


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n\n')[0])
    sub = ap.add_subparsers(dest='cmd', required=True)
    sub.add_parser('status')
    sub.add_parser('worklist').add_argument('-n', type=int, default=20)
    sub.add_parser('progress')
    p = sub.add_parser('check')
    p.add_argument('function', help='name or address')
    p.add_argument('--diff', action='store_true', help='Show target/built disassembly when not matching')
    sub.add_parser('verify')
    args = ap.parse_args()
    {'status': cmd_status, 'worklist': cmd_worklist, 'progress': cmd_progress, 'check': cmd_check, 'verify': cmd_verify}[args.cmd](args)


if __name__ == '__main__':
    main()
