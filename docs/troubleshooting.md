# Troubleshooting

## Build

- `as` warns "section does not have enough alignment to ensure safe PC-relative loads": expected for Thumb
  functions at 2-mod-4 addresses (`build.md`, notes). The SHA1 check decides.
- `ninja verify` fails right after editing `layout.txt` or `symbols.txt`: the disassembler re-ran; check the
  new `asm/manifest.txt` and that every region still has a mode.
- Non-ASCII bytes in a source or doc: `LC_ALL=C grep -nP '[^\x00-\x7F]' <file>` finds them.

## C functions

- configure.py or the judge refuses a target: it is not 4-aligned (an agbcc object starts 4-aligned), or it
  lies outside the Thumb game code (`0x08000180`-`0x08043C3C`).
- Link error "undefined reference to `gUnknown_XXXXXXXX`": the `data` line is missing from symbols.txt (a
  `disasm.py discover` rewrites the file; re-add the lines, `build.md` "C functions").
- Judge says match, verify fails: a wrong callee or data name (the judge masks relocations). Run the workspace
  `precheck_syms.py` and `check.py` referents, compare the target's `bl` targets and pool words.
- Prologue or epilogue differ for every attempt: check the compiler is `old_agbcc` with the full flag set
  (`compiler.md`; without `-mtpcs-leaf-frame` no leaf matches). Never change the flags to fit one function.

## Compiler

- `tools/setup_agbcc.sh` fails to assemble libgcc: install Homebrew `arm-none-eabi-binutils` (or put
  devkitARM's `bin` on `PATH`) and rerun; the script is idempotent.
- `tools/probe_compiler.py` reports a size mismatch: pass the size explicitly when the next symbol is not the
  function end (padding, data after the function).
