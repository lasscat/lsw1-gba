#!/usr/bin/env python3
"""Candidate judge: compiles ONE worker C file for ONE assigned function and compares it with the original bytes.

    judge.py prepare --project ROOT --target NAME --evidence E.json --out JOB/assignment.json [--reference src/x.c]
    judge.py judge --assignment JOB/assignment.json --file JOB/scratch/NAME.c [--summary]

`prepare` (coordinator) admits a target: a Thumb game function of symbols.txt that is still asm. It records the repo
HEAD/branch, the target span and hashes of the build context (tools, config, headers, the compiler) in assignment.json.
`judge` refuses stale assignments, fake matches (tools/fakematch.py) and sources that need asm approval, compiles with
project.compile_c (the build's exact commands and flags), checks the object holds exactly the assigned function, and
compares its .text with the ROM span (literal-pool words and bl halves the object leaves to the linker are masked).
Every try is kept under JOB/attempts/<id>/ (record.json, candidate.c/.o/.s, target.bin, candidate.bin, byte-diff.json,
object.json) and in JOB/missdb.sqlite; JOB/latest.json names the newest. Job records live outside the repo, never in
/tmp. A candidate-match is a lead: integrate it, then only `tools/match.py verify` (full ROM SHA1) proves it.
"""
import argparse
import hashlib
import json
import os
import sqlite3
import subprocess
import sys
import time
import uuid
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import project  # noqa: E402  (every path and flag: tools/project.py)

COMPILE_TIMEOUT = 30
NOTE = 'Candidate diagnostic only; full-ROM verification NOT RUN'


def digest(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def run(cmd, root):
    return subprocess.run(cmd, cwd=root, capture_output=True, text=True)


def emit(record, summary=False, path=None):
    if summary:
        fields = ('kind', 'target', 'language', 'profile', 'status', 'diffs', 'total', 'size', 'raw_equal',
                  'integrated', 'artifact_dir')
        result = {k: record[k] for k in fields if k in record}
        result['record'] = str(path) if path else None
        error = str(record.get('error', '')) or '; '.join(record.get('problems', [])[:3])
        if not error and record.get('status') == 'compile' and record.get('artifact_dir'):
            log = Path(record['artifact_dir']) / 'compiler.stderr'
            if log.exists():
                error = log.read_text(errors='replace')[:400]
        result['error'] = error[:400]
        result['note'] = NOTE
        print(json.dumps(result))
    else:
        print(json.dumps(record))


def git(root, *args):
    p = run(['git', *args], root)
    if p.returncode:
        raise ValueError(p.stderr.strip() or 'git ' + ' '.join(args) + ' failed')
    return p.stdout.strip()


def head(root):
    """The commit of HEAD, or 'unborn' for a branch with no commits yet (any other git failure is an error)."""
    p = run(['git', 'rev-parse', '--verify', '-q', 'HEAD'], root)
    if p.returncode == 0:
        return p.stdout.strip()
    import check_source_policy
    if check_source_policy.unborn(root):
        return 'unborn'
    raise ValueError('cannot resolve HEAD')


def outside_game(path, root):
    path = Path(path).resolve()
    if path == root or root in path.parents:
        raise ValueError('durable paths must be outside the game checkout')
    temporary = Path('/tmp').resolve()
    if path == temporary or temporary in path.parents:
        raise ValueError('durable records must not live in /tmp')
    return path


def atomic_json(path, value):
    tmp = path.with_name(path.name + '.tmp-' + uuid.uuid4().hex)
    with tmp.open('x') as f:
        json.dump(value, f, indent=2)
        f.write('\n')
        f.flush()
        os.fsync(f.fileno())
    os.replace(tmp, path)


def record_attempt(database, record):
    """Every try (refusals, errors, matches) is kept; DB errors fail closed. Never replay-eligible."""
    with sqlite3.connect(database, timeout=60) as c:
        c.execute('PRAGMA journal_mode=WAL')
        c.execute('''CREATE TABLE IF NOT EXISTS candidate_attempts (
            id TEXT PRIMARY KEY, project TEXT NOT NULL, head TEXT NOT NULL,
            module TEXT NOT NULL, target TEXT NOT NULL, language TEXT NOT NULL,
            profile TEXT NOT NULL, source_sha256 TEXT NOT NULL, status TEXT NOT NULL,
            replay_eligible INTEGER NOT NULL CHECK(replay_eligible = 0),
            artifact_dir TEXT NOT NULL, record_json TEXT NOT NULL)''')
        c.execute('INSERT INTO candidate_attempts VALUES (?,?,?,?,?,?,?,?,?,0,?,?)', (
            record['id'], record['root'], record['head'], record['module'], record['target'],
            record['language'], record['profile'], record['source_sha256'], record['status'],
            record['artifact_dir'], json.dumps(record)))


def protected_files(root):
    """Build context an assignment is judged against: a change to any of these makes it stale."""
    files = [project.TOOLS / n for n in ('project.py', 'configure.py', 'judge.py', 'fakematch.py', 'probe_compiler.py',
                                         'check_source_policy.py', 'verify.py', 'match.py')]
    files += sorted(project.CONFIG.glob('*.txt')) + [project.LD_SCRIPT, project.SHA1_FILE, project.CC]
    files += sorted(p for p in project.INCLUDE.rglob('*') if p.is_file())
    files += sorted(p for p in (project.AGBCC.parent / 'include').rglob('*') if p.is_file())
    if project.ASM_APPROVALS.exists():
        files.append(project.ASM_APPROVALS)
    out = {}
    for p in files:
        p = Path(p).resolve()
        out[str(p.relative_to(root)) if root in p.parents else str(p)] = digest(p)
    return out


def changed_context(root, protected):
    return next((p for p, sha in protected.items() if not (root / p).is_file() or digest(root / p) != sha), None)


def prepare(a):
    root = Path(a.project).resolve()
    if root != project.ROOT:
        raise ValueError(f'--project {root} is not the repo this judge belongs to ({project.ROOT})')
    dest = outside_game(a.out, root)
    if dest.exists():
        raise ValueError('assignment already exists; use a new job directory')
    problems = project.toolchain_problems()
    if problems:
        raise ValueError('; '.join(problems))
    found = project.symbol_by_name(a.target)
    if found is None:
        raise ValueError(f'{a.target} is not in {project.rel(project.SYMBOLS)}')
    addr, kind = found
    name = project.read_symbols()[addr][1]
    if kind != 'thumb':
        raise ValueError(f'{name} is {kind}: only Thumb functions have a probed compiler (docs/compiler.md)')
    if not project.GAME_CODE[0] <= addr < project.GAME_CODE[1]:
        raise ValueError(f'{name} is library code: agbcc is probed for game code only (docs/compiler.md)')
    if any(name in names for _, names in project.read_sources()):
        raise ValueError(f'{name} is already in C ({project.rel(project.SOURCES)})')
    if addr % 4:
        raise ValueError(f'{name} is not 4-aligned: an agbcc object starts 4-aligned (tools/configure.py)')
    span = project.symbol_span(addr)
    reference = None
    if a.reference:
        ref = Path(a.reference)
        if ref.is_absolute() or '..' in ref.parts or ref.suffix != '.c':
            raise ValueError('reference must be a repo-relative .c source')
        if str(ref) not in {c for c, _ in project.read_sources()}:
            raise ValueError(f'reference {ref} is not linked ({project.rel(project.SOURCES)})')
        git(root, 'ls-files', '--error-unmatch', str(ref))
        if git(root, 'status', '--porcelain', '--', str(ref)):
            raise ValueError('reference source must be committed and unmodified')
        reference = str(ref)
    evidence = json.loads(Path(a.evidence).read_text())
    for key in ('authorization', 'prior_findings', 'calls', 'literals', 'language_evidence'):
        if key not in evidence:
            raise ValueError('missing evidence field: ' + key)
    argv = [[project.CPP, *project.CPP_ARGS], [project.rel(project.CC) if root in project.CC.parents
                                               else str(project.CC), *project.CC_FLAGS],
            [project.binutil('as'), *project.AS_FLAGS]]
    manifest = dict(kind='code', root=str(root), branch=git(root, 'branch', '--show-current'), head=head(root),
                    target=name, module=project.VERSION, start=addr, end=addr + span, mode=kind, language='c',
                    profile='agbcc ' + ' '.join(project.CC_FLAGS), reference=reference,
                    reference_sha256=digest(root / reference) if reference else None, argv=argv, evidence=evidence,
                    protected=protected_files(root))
    dest.parent.mkdir(parents=True, exist_ok=True)
    atomic_json(dest, manifest)
    emit(manifest, getattr(a, 'summary', False), dest)


def inspect_object(obj, target, span):
    """Function-only contract: the only allocated contents are .text, which starts with the assigned function, is
    the only function defined, and is the target span long (function, literal pool, END_PAD)."""
    secs = project.elf_sections(obj)
    syms = project.elf_symbols(obj)
    alloc = [dict(name=n, size=size, flags=flags) for n, _t, flags, _o, size in secs if flags & 2 and size]
    problems = []
    if any(s['name'] != '.text' for s in alloc):
        problems.append('unexpected allocatable section (function-only contract): '
                        + ', '.join(s['name'] for s in alloc if s['name'] != '.text'))
    defined = [s[0] for s in syms if s[4] == 2 and s[5] != 0]
    if defined != [target]:
        problems.append(f'expected only the assigned function {target}, object defines {defined}')
    entry = next((s for s in syms if s[0] == target and s[4] == 2 and s[5] != 0), None)
    if entry is None or entry[3] != 1:
        problems.append(f'{target} is not a global function')
    elif entry[1] & ~1:
        problems.append(f'{target} does not start the .text section')
    elif not entry[1] & 1:
        problems.append(f'{target} is not Thumb code')
    text = next((s for s in alloc if s['name'] == '.text'), None)
    if text and text['size'] != span:
        problems.append(f'.text is {text["size"]:#x} bytes, the target span is {span:#x}')
    relocs = [dict(offset=o, type=t, symbol=n, size=sz) for o, t, n, sz in project.elf_relocs(obj)]
    return dict(allocatable=alloc, symbols=[list(s) for s in syms], relocations=relocs, problems=problems)


def text_bytes(obj):
    sec = next(s for s in project.elf_sections(obj) if s[0] == '.text')
    return Path(obj).read_bytes()[sec[3]:sec[3] + sec[4]]


def compare(target, cand, relocs):
    """(differing halfwords, total). Halfwords the object leaves to the linker (relocations) are masked; every other
    halfword, including literal-pool constants, must be equal."""
    n = len(target) // 2
    if len(cand) != len(target):
        return n, n
    masked = {(o + k) // 2 for o, _t, _n, size in relocs for k in range(0, size, 2)}
    return sum(1 for i in range(n) if i not in masked and target[2 * i:2 * i + 2] != cand[2 * i:2 * i + 2]), n


def judge(a):
    assignment_path = Path(a.assignment).resolve()
    m = json.loads(assignment_path.read_text())
    root = Path(m['root']).resolve()
    if root != project.ROOT:
        raise ValueError(f'assignment root {root} is not the repo this judge belongs to ({project.ROOT})')
    outside_game(assignment_path, root)
    if head(root) != m['head'] or git(root, 'branch', '--show-current') != m['branch']:
        raise ValueError('assignment HEAD/branch is stale; coordinator must re-admit target')
    changed = changed_context(root, m['protected'])
    if changed:
        raise ValueError('assignment build context changed: ' + changed)
    if m.get('reference') and digest(root / m['reference']) != m['reference_sha256']:
        raise ValueError('reference source changed')
    source_path = Path(a.file).resolve()
    if source_path.suffix != '.c':
        raise ValueError('candidate must be a .c file (assignment language c)')
    store = outside_game(assignment_path.parent, root)
    identity = uuid.uuid4().hex
    dest = store / 'attempts' / identity
    dest.mkdir(parents=True, exist_ok=False)
    raw = source_path.read_bytes()
    saved = dest / 'candidate.c'
    saved.write_bytes(raw)
    record = dict(m, id=identity, artifact_dir=str(dest), source_sha256=digest(saved),
                  assignment_sha256=digest(assignment_path), timestamp=time.time(), status='refused',
                  integrated=False, replay_eligible=False,
                  note='Diagnostic only; calls/literals need review; full-ROM verify NOT RUN')
    from fakematch import fake_match
    import check_source_policy
    try:
        why = fake_match(raw.decode('ascii'), project.allowed_head())
        if check_source_policy.needs_approval(saved.name, raw):
            why = 'assembly requires per-source human approval; the judge accepts natural source only'
    except UnicodeDecodeError:
        why = 'source is not ASCII'
    if why:
        record['error'] = 'fake-match guard: ' + why
    else:
        obj = dest / 'candidate.o'
        try:
            p = project.compile_c(saved, obj, timeout=COMPILE_TIMEOUT)
            (dest / 'compiler.stdout').write_text(p.stdout)
            (dest / 'compiler.stderr').write_text(p.stderr)
            record['returncode'] = p.returncode
            if p.returncode or not obj.exists():
                record['status'] = 'compile'
            else:
                span = m['end'] - m['start']
                audit = inspect_object(obj, m['target'], span)
                atomic_json(dest / 'object.json', audit)
                for tool, args, log in [('readelf', ['-SWsr'], 'readelf.txt'), ('objdump', ['-dr'], 'object.diff.txt')]:
                    view = run([project.binutil(tool), *args, str(obj)], root)
                    (dest / log).write_text(view.stdout + view.stderr)
                record['status'] = 'object-blocked'
                record['problems'] = audit['problems']
                cand = text_bytes(obj)
                target = project.rom_bytes(m['start'], span)
                (dest / 'target.bin').write_bytes(target)
                (dest / 'candidate.bin').write_bytes(cand)
                if not audit['problems']:
                    relocs = project.elf_relocs(obj)
                    bad, n = compare(target, cand, relocs)
                    record.update(diffs=bad, total=n, size=len(cand), raw_equal=cand == target,
                                  relocations=[[o, t, s] for o, t, s, _ in relocs],
                                  status='candidate-match' if bad == 0 else 'unmatched')
                atomic_json(dest / 'byte-diff.json', {'target_size': len(target), 'candidate_size': len(cand),
                            'differences': [[i, x, y] for i, (x, y) in enumerate(zip(target, cand)) if x != y]})
        except subprocess.TimeoutExpired as e:
            record.update(status='compile-timeout', error=str(e))
        except (OSError, ValueError, IndexError, StopIteration) as e:
            record.update(status='tool-error', error=str(e))
    if head(root) != m['head']:
        record.update(status='stale', error='HEAD changed during judging')
    if changed_context(root, m['protected']):
        record.update(status='stale', error='build context changed during judging')
    atomic_json(dest / 'record.json', record)
    record_attempt(store / 'missdb.sqlite', record)
    atomic_json(store / 'latest.json', {'id': identity, 'record': str(dest / 'record.json')})
    emit(record, getattr(a, 'summary', False), dest / 'record.json')


def main():
    p = argparse.ArgumentParser(description=__doc__.split('\n\n')[0])
    sub = p.add_subparsers(dest='command', required=True)
    s = sub.add_parser('prepare')
    s.add_argument('--project', default=str(project.ROOT))
    s.add_argument('--target', required=True)
    s.add_argument('--evidence', required=True)
    s.add_argument('--out', required=True)
    s.add_argument('--reference', help='a committed, linked src/*.c to show the worker (optional)')
    s.add_argument('--summary', action='store_true')
    s.set_defaults(fn=prepare)
    s = sub.add_parser('judge')
    s.add_argument('--assignment', required=True)
    s.add_argument('--file', required=True)
    s.add_argument('--summary', action='store_true')
    s.set_defaults(fn=judge)
    a = p.parse_args()
    try:
        a.fn(a)
    except (ValueError, OSError, KeyError, sqlite3.Error, subprocess.TimeoutExpired) as e:
        # Admission failures happen before compiling; keep those too. An invalid or non-durable assignment path never
        # grants a new write location.
        if a.command == 'judge':
            try:
                manifest = json.loads(Path(a.assignment).read_text())
                store = outside_game(Path(a.assignment).resolve().parent, Path(manifest['root']).resolve())
                dest = store / 'attempts' / ('blocked-' + uuid.uuid4().hex)
                dest.mkdir(parents=True, exist_ok=False)
                src = Path(a.file)
                if src.is_file():
                    (dest / ('candidate' + src.suffix)).write_bytes(src.read_bytes())
                atomic_json(dest / 'record.json', dict(status='blocked', error=str(e), integrated=False,
                            assignment=a.assignment, candidate=a.file, timestamp=time.time()))
            except (OSError, ValueError, KeyError):
                pass
        print(json.dumps({'status': 'blocked', 'error': str(e), 'integrated': False}), file=sys.stderr)
        return 1
    return 0


if __name__ == '__main__':
    sys.exit(main())
