# Agent contract (LEGO Star Wars GBA decomp)

Matching decomp: every build must reproduce the original ROM byte for byte. Game code is GCC Thumb, built with
`old_agbcc -O2 -mthumb-interwork -mtpcs-frame -mtpcs-leaf-frame` (docs/compiler.md). Setup alone authorizes
no reconstruction, integration, commit or publication; the current user request sets the scope.

## Non-negotiable gates

- Only the unchanged `venv/bin/python tools/match.py verify` ending in `VERIFY PASSED` (ROM SHA1 equal to
  `config/usa/baserom.sha1`) proves a match. Judge scores, `match.py check` and candidate-match statuses are
  leads, never counts.
- Never weaken compiler flags, the verifier, the judge's fake-match guard or `tools/check_source_policy.py`,
  and never edit them to make something pass.
- Natural clean-room C, ASCII. No inline asm, `__attribute__`, preprocessor tricks, opcodes or ROM bytes as
  numbers/arrays (docs/source-policy.md). New assembly sources need a hash-bound human approval in
  `config/asm_approvals.json`; an agent never approves its own.
- Never commit the ROM, `extract/`, `asm/`, `build/` or other ROM-derived output. Stage exact paths, never
  `git add .` or `git add -u`.
- Before each commit: `venv/bin/python tools/check_source_policy.py --staged`. Pushing or adding a remote
  needs the owner's explicit OK.

## Ownership

- One coordinator owns shared writes, builds and integration. Workers edit only their own job scratch
  directory and keep every attempt.
- Functions use `config/usa/symbols.txt` names (`sub_XXXXXXXX`; RAM globals reached by address only:
  `gUnknown_XXXXXXXX`). A C function is linked by a `config/usa/sources.txt` line (docs/build.md).
- Scope: Thumb game functions at 4-aligned addresses. Library code (0x080477C0 onward), data and C++ are
  out of scope until a compiler probe and the docs cover them.
- A failed verify, policy check or commit means STOP and keep the evidence; no automatic rollback or retry.

## References

docs/build.md (build, C functions), docs/compiler.md (agbcc, probes), docs/source-policy.md,
docs/troubleshooting.md, docs/rom-survey.md.
