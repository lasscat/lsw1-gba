# Building the ROM (asm rebuild, C functions swapped in)

Needs: your own ROM in `extract/` (see `extract/README.md`), GNU binutils for `arm-none-eabi` (`as`, `ld`,
`objcopy`; Homebrew `arm-none-eabi-binutils` or devkitARM), ninja, Python 3 with `capstone` (`tools/requirements.txt`).

```sh
python tools/configure.py      # writes build.ninja; runs tools/disasm.py emit if asm/ is missing
ninja                          # asm/*.s -> build/usa/obj/*.o -> build/usa/lsw1_usa.elf -> build/usa/lsw1_usa.gba
ninja verify                   # tools/verify.py: VERIFY PASSED only if the SHA1 equals config/usa/baserom.sha1
```

`build.ninja` depends on `asm/manifest.txt`, which depends on `tools/disasm.py`, `config/usa/layout.txt`,
`config/usa/symbols.txt` and the ROM, so editing the layout or a symbol name re-runs the disassembler and the
configure step by itself. Unchanged files keep their timestamps, so only what changed is reassembled.

## What is tracked and what is not

Tracked: `config/usa/layout.txt` (segments and ARM/Thumb/data regions, addresses only),
`config/usa/symbols.txt` (function starts and names), `config/usa/ld_script.ld`, the tools.
Git-ignored, never committed: the ROM, everything under `asm/` (generated from the ROM: instruction text and
`asm/bin/*.bin` slices) and `build/`.

## Disassembler choice: a capstone script (`tools/disasm.py`)

- **Load segments.** crt0 copies IWRAM code (Krawall mixer, `intr_main`) and EWRAM data out of the ROM, so those
  bytes are linked at 0x03000000/0x02000000 but stored after the ROM image. `layout.txt` describes segments with
  separate run and load addresses, and the linker script mirrors them. gbadisasm and luvdis work on ROM
  addresses; using them here would have meant post-processing their output.
- **ARM and Thumb mixed.** The ROM has ARM crt0, ARM libgcc division, Krawall ARM routines, ld interworking glue
  and long-call stubs between Thumb regions (survey). The script takes the mode per region from `layout.txt`.
- **Reassembly by construction.** Every distinct instruction text is assembled once with the same GNU `as` the
  build uses; any text whose bytes differ from the ROM is written as `.inst`/`.inst.n` with the text as a
  comment (15 in the whole ROM). The final proof is still `tools/verify.py`.
- **Public repo.** Config holds only addresses, modes and names; ROM-derived output stays in ignored `asm/`.
- capstone 5 was already in use for the survey, so nothing new to build.

## C functions (phase 5)

`config/usa/sources.txt` lists `src/<file>.c name [name...]`. For each line `tools/configure.py` drops those
functions' `asm/code/<name>.s` from the link and links the C object at the first function's place. The C build is
`clang -E` -> `old_agbcc` (flags: `tools/project.py`, why: `docs/compiler.md`) -> append `END_PAD`
(`\t.align\t2, 0`, the pad agbcc leaves to the assembler) -> `as`. The judge compiles with the same steps
(`project.compile_c`), so a judge match and the ROM build see the same object.

- Alignment: an agbcc object starts 4-aligned, so a function at a 2-mod-4 address cannot be C yet (4 of 1965
  game functions). configure.py and the judge's `prepare` refuse it.
- Names: C must use `config/usa/symbols.txt` names. A RAM global the asm reaches only by address is named
  `gUnknown_XXXXXXXX` (an address outside every segment). The workspace `integrate_one.py` adds it to symbols.txt
  as `data`, and configure.py defines it in the generated `build/usa/c_symbols.ld`, with the Thumb aliases
  `_XXXXXXXX` that other asm files use for the swapped function. `disasm.py discover` rewrites symbols.txt, so
  re-add those lines after a rediscover.
- `python tools/match.py check <name>` diffs one C function against the ROM. `python tools/match.py verify`
  builds, runs `tools/verify.py` and the source policy, and is the only proof. The judge
  (`tools/judge.py`) masks relocated halfwords (calls, pool words). The workspace `diffcore.py` (referents) and
  `precheck_syms.py` catch a wrong callee or data name before the link.

## Progress report (ByteMatch)

`tools/configure.py` also writes `objdiff.json` (git-ignored): one unit per `asm/code/` function, category `game`
or `lib`. The target is the function's asm object; a function in `sources.txt` also gets its C object as the base
and `complete: true`. `ninja report` assembles the target objects the ROM no longer links and runs
[objdiff-cli](https://github.com/encounter/objdiff) (`./objdiff-cli` in the repo root, git-ignored; or
`configure.py --objdiff <path>`). It writes `build/usa/report.json` and `progress/report.json.gz`.

So that a matched function scores 100% in objdiff, `tools/disasm.py` lays out pads the way agbcc objects do:
a trailing zero halfword (END_PAD) comes after `func_end`, outside the symbol size, and a zero halfword before a
literal pool is `.2byte 0x0000` data. Both leave the bytes unchanged.

Committing `progress/report.json.gz` publishes progress. CI cannot build without the ROM, so
`.github/workflows/progress.yaml` only unpacks the committed report into the `BLWE_report` artifact that
[ByteMatch](https://bytematch.dev/lasscat/lsw1-gba) reads from successful pushes to `main`. The report holds unit
and function names, sizes and match percentages, and no ROM bytes.

## Notes for later phases

- `as` prints "section does not have enough alignment to ensure safe PC-relative loads" for Thumb functions
  at 2-mod-4 addresses (one section per file, alignment 2). That is expected: link order places them, and the
  SHA1 check proves the result.
- A jump-table entry or even pool word that points at a Thumb function start refers to a plain alias label
  `_XXXXXXXX` emitted at that start: ld would set bit 0 on a reference to the `%function` symbol.
- Layout fix found by the rebuild: `0x08044114..0x080441D0` is a data blob (ends `LEGOSTARWARSBLWE4F`) that the
  ARM routine at 0x08044110 branches over.
