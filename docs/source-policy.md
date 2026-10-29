# Source policy

Every reconstructed function is natural, clean-room C that compiles to the original bytes with the project
flags (`docs/compiler.md`). C++ and the library code (`0x080477C0` onward) are out of scope for now.

## Refused outright

`tools/fakematch.py` (used by `tools/judge.py` before compiling) refuses a candidate that contains:

- inline assembly (`asm`, `__asm__`), `__attribute__`, `_Pragma` or `##`;
- assembler directives (`.word`, `.byte`, `.inst`, `.section`, `.incbin`, ...);
- Thumb opcodes written as numbers (push/pop/bx lr/bl halfwords);
- any preprocessor line that the starting source did not already have.

Express intent with `enum`, `typedef`, `struct` and `static inline` functions instead of new macros or
includes. ROM bytes never appear in sources as numbers or arrays.

## Marked exceptions (shown to the owner before integration)

- A steering construct that only exists to reproduce the original code generation (dead store, duplicated
  compare, always-true test) is first tried as a `static inline` helper; if it must stay, the line carries
  `// FAKE: <reason>`.
- `volatile` is a last resort: a local cast, never a struct field or global, marked `// FAKE: <reason>`.

The FAKE ledger is `grep -rn "// FAKE:" src`.

## Assembly sources

A changed `.s`/`.inc` file, or C that uses `asm`, needs a hash-bound human approval in
`config/asm_approvals.json`:

```json
{ "src/auto/sub_XXXXXXXX.s": { "reason": "...", "approved_by": "<owner>", "approval": "<where/when>",
                               "sha256": "<sha256 of the exact file bytes>" } }
```

An agent never writes its own approval. `tools/check_source_policy.py` checks every changed source against
`--base <rev>` (default `HEAD`; before the first commit, the empty tree); `--staged` checks the index. Both run
before each commit. The policy check is a tripwire, not proof: only `tools/match.py verify` ending in
`VERIFY PASSED` proves a match.
