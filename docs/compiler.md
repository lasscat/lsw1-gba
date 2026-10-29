# Compiler

**Result (phase 4, 2026-10-29):** the game's Thumb code is reproduced by **`old_agbcc` with
`-O2 -mthumb-interwork -mtpcs-frame -mtpcs-leaf-frame`**, using pret's agbcc with one patch. Four game functions
match instruction for instruction, with `bl` targets and literal-pool words masked (table below). This is a lead,
not proof: only `ninja verify` (ROM SHA1) proves a match, and that needs C linked into the build (phase 5).

## Setup

```sh
tools/setup_agbcc.sh        # about 30 s; idempotent
```

The script clones pret/agbcc at a pinned commit into `tools/agbcc/src` (git-ignored) and applies
`tools/agbcc-tpcs-frame.patch`. It then runs upstream `build.sh` natively (Apple clang; needs Homebrew
`arm-none-eabi-binutils` for `as`/`ar`) and installs `agbcc`, `old_agbcc`, `agbcc_arm`, headers and
`libgcc.a`/`libc.a` into `tools/agbcc/{bin,include,lib}`. Last, it checks that an empty function gets the backtrace
frame. Everything downloaded is open source. No SDK compiler binaries are used.

agbcc is a bare `cc1`: it reads preprocessed C and writes assembly. The pipeline is
`clang -E -undef -nostdinc -I tools/agbcc/include` -> `old_agbcc FLAGS` -> `arm-none-eabi-as -mcpu=arm7tdmi`.

## Why the patch

Every game function starts with the TPCS backtrace frame (`sub sp,#16 ... mov fp,rX`). It returns through
`pop {..}; mov fp,..; mov sp,..; bx ..` (`docs/rom-survey.md`). This holds even for empty leaf functions, so the game
was built with `-mtpcs-frame -mtpcs-leaf-frame`. pret removed both options in commit d28ac43 ("clean up thumb
code"). The patch restores them from `git show d28ac43^:gcc/config/arm/thumb.c`:
- `thumb.h`: the two flags, `TARGET_BACKTRACE`, and the frame offset in `INITIAL_ELIMINATION_OFFSET`.
- `thumb.c`: the full `thumb_exit` (pops FP and SP), the backtrace prologue, and the epilogue register mask.

With the flags off, the output is unchanged. The patch is GPL-2.0-or-later, like agbcc.

## Probes

`tools/probe_compiler.py SOURCE FUNCTION ADDRESS [SIZE]` compiles `SOURCE` with each agbcc build under several
flag sets. It compares one function with the ROM; the size defaults to the next symbol in `config/usa/symbols.txt`,
minus trailing zero padding. `--show` prints both disassemblies side by side. The probes are clean-room C in
`tools/probes/phase4.c`.

| Function | What it does | `old_agbcc -O2` | `agbcc -O2` | `old_agbcc -O1` |
|---|---|---|---|---|
| `0x0800C364` | empty stub (also `0x0800C9AC`, ...) | MATCH | MATCH | MATCH |
| `0x08000494` | `p->flags \|= 2; p->flags &= ~1` | MATCH | MATCH | 2 diffs |
| `0x080005BC` | OR bits into every node of a global list | MATCH | size differs | MATCH |
| `0x08000A74` | set bit 0 of `p->slots[i]` (12-byte elements) | MATCH | 2 diffs | MATCH |

(`agbcc`/`old_agbcc` columns use the full game flags. Without `-mtpcs-leaf-frame` no leaf matches.)
`-fprologue-bugfix` exists only in the new `agbcc`. `old_agbcc` is pret's build with `-DOLD_COMPILER`.

Not yet checked: the library code (`0x080477C0` onward: SWI wrappers, memcpy/strlen, libgcc) may come from a
different build; probe it when those functions get C.
