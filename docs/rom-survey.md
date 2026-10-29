# ROM survey (phase 2)

Target: `LEGOSTARWARS`, game code `BLWE`, maker `4F`, version 0, 16777216 B, SHA1 in `config/usa/baserom.sha1`.
All addresses are GBA bus addresses (ROM = file offset + 0x08000000). Byte evidence is kept to a few
instruction words per claim; no ROM data or asm dumps go in this repo. Surveyed 2026-10-29 with GNU binutils
2.47 (`arm-none-eabi-objdump`) and capstone 5.0.7.

## Layout

| Range | Contents | Evidence |
|---|---|---|
| 0x08000000-0x080000C0 | GBA header | entry word `ea00002e` = `b 0x080000C0` |
| 0x080000C0-0x08000180 | crt0 (ARM) + literals at 0x08000144-0x08000170 | see crt0 below |
| 0x08000180-~0x08043B3C | game code (Thumb, GCC, tpcs-frame) | ~833 prologues `b084 b5xx` |
| 0x08043C3C-0x08044278 | ARM signed div/divmod helpers (hand-written) | starts `e2113102` (`ands r3,r1,#0x80000000`) |
| 0x08044278-0x080477C0 | libraries: Krawall Thumb + others, no tpcs-frame | returns `bc01 4700` (`pop{r0}; bx r0`) |
| 0x08044770-0x08044924 | Krawall ARM routine, APCS frame | `e1a0c00d e92dd830 e24cb004` |
| 0x080477C0-0x080477F8 | BIOS SWI wrappers (Thumb) | `svc N; bx lr` (`df0b 4770` etc.) |
| 0x080477F8-0x08047A40 | C library: memset-like, memcpy, strlen | see libraries below |
| 0x08047A40-0x08047D1A | libgcc (`_call_via_rX`, div/mod) | `0047 c046 0847 c046 ...` |
| 0x08047D1C-0x08047D9C | GNU ld interworking glue | `7847 c046` + `eaxxxxxx` |
| 0x08047D9C-0x08EBF030 | data (~14.5 MB); BL density per 8 KB is 0 from 0x08048000 | `dens.py` sweep |
| 0x08EBF030-0x08EC1508 | IWRAM image (size 0x24D8), copied to 0x03000000 | crt0 copy loop |
| 0x08EC1508-0x08EC3D00 | EWRAM image (size 0x27F8), copied to 0x02000000 | crt0 copy loop |
| ~0x08EC3D00-0x09000000 | 0xFF padding | |

About 1161 distinct BL targets, all below 0x08048000.

## crt0 (0x080000C0, ARM)

- IRQ-mode sp = 0x03007FA0, system-mode sp = 0x03007F00 (SDK defaults).
- Clears 0x03000000-0x03008000, then copies IWRAM 0x03000000-0x030024D8 from 0x08EBF030 and EWRAM
  0x02000000-0x020027F8 from 0x08EC1508 (the two images are contiguous).
- Stores 0x03000200 to 0x03007FFC (IRQ vector), `bx` to 0x08012D09 (Thumb `AgbMain`), then `b 0x080000C0`.
- Shape: Nintendo AGB SDK `crt0.s` with section clear/copy loops added (GNU ld style load/run split).

## IWRAM image (0x03000000)

- 0x030001D0 / 0x030001E8: ARM IRQ enable/disable helpers (`mrs r0,CPSR; bic/orr r0,#0x80; msr; bx lr`).
- 0x03000200: IRQ handler = AGB SDK `crt0.s` `intr_main`, multiple-interrupt variant. Starts
  `mov r3,#0x4000000; add r3,r3,#0x200; ldr r2,[r3]; ldrh r1,[r3,#8]; mrs r0,spsr; stmfd sp!,{r0-r3,lr}`.
- ARM code to about 0x03002074, then data. 9 APCS frames (`mov ip,sp` = `e1a0c00d`), 36 `bx lr`. Some
  functions are frameless with large register saves, e.g. 0x03000330 `e92d5ff6` (`stmfd {r1,r2,r4-r12,lr}`),
  likely the Krawall mixer (`-marm -O2` or hand asm).
- Called from ROM through GNU ld long-branch stubs (`push{r0}; ldr r0,[pc,#8]; mov ip,r0; pop{r0}; bx ip`) to
  0x03000330, 0x030009A8, 0x0300065C, 0x03000BA4, 0x03000CF0, 0x03000E58.

## EWRAM image (0x02000000)

Data only, mostly zero (initialized .data).

## Libraries and version strings

- **Krawall** (Sebastian Kienzl): `$Id: player.c,v 1.4 2003/03/19 23:12:15 seb Exp $` at 0x08071AD8. The
  tables before it point to 0x08044770 (ARM, from 0x08071AB4 and 0x08071AD4), Thumb 0x080469DD (from
  0x08071B18), 0x080469F5 (from 0x08071B24), and IWRAM 0x0300152C/0x03001650/0x030018D8. Krawall was later
  open-sourced, which helps identify its functions.
- **AGB SDK**: crt0 + `intr_main` (above). No "AGB" version string (the two "AGB" hits at 0x0807BF73 and
  0x08396A69 are inside data).
- **BIOS wrappers** 0x080477C0-0x080477F6: SWI 0x0A, 0x0C CpuFastSet, 0x0B CpuSet, 0x06 Div, DivMod
  (`svc 6; adds r0,r1,#0`), 0x13, 0x12 LZ77->VRAM, 0x11 LZ77->WRAM, 0x0F, 0x15, 0x14, `movs r2,#0; svc 5`
  (VBlankIntrWait). The `adds r0,r1,#0` move is a GCC idiom.
- **C library**: 0x080477F8 byte-fill loop (memset/bzero), 0x08047814 memcpy (aligned `ldmia/stmia` path),
  0x080479F4 newlib-style strlen (word-at-a-time with 0xFEFEFEFF / 0x80808080).
- **libgcc** (`lib1funcs.asm`, Thumb): `_call_via_r0..lr` at 0x08047A40-0x08047A7A; `__divsi3` 0x08047A7C
  (returns `mov pc,lr` = `46f7`); `__div0` stub 0x08047B10 (`mov pc,lr`); `__modsi3` 0x08047B14; further
  udiv/umod to 0x08047D1A.
- **Build stamp**: `Jan 25 2005` (`__DATE__`) at 0x0804F4E8.
- Other plain text is almost absent ("Sound Test" at 0x0804CAFC); game text is encoded or compressed.

## ARM vs Thumb

ARM only at: crt0 (0x080000C0-0x08000180), div helpers (0x08043C3C-0x08044278), the Krawall routine
(0x08044770-0x08044924), the 4-byte `b` halves of the ld glue, and the IWRAM code. Everything else that is
code is Thumb. Short ARM-looking runs inside the Thumb area were checked and are data tables.

## Compiler fingerprint

Game code is **GCC, Thumb, `-mthumb-interwork -mtpcs-frame`**, old (2.9x/3.x) backend:

- Backtrace prologue (`thumb.c` TARGET_BACKTRACE), first function 0x08000180:
  `b084 b530 ad07 9504 467d 9506 465d 9503 4675 9505 ad06 46ab`
  (`sub sp,#16; push{r4,r5,lr}; add r5,sp,#28; str r5,[sp,#16]; mov r5,pc; str; mov r5,fp; str; mov r5,lr; str;
  add r5,sp,#24; mov fp,r5`).
- Matching epilogue `bc07 468b 4695 4700` (`pop{r0,r1,r2}; mov fp,r1; mov sp,r2; bx r0`) occurs 1226 times,
  e.g. 0x080001D4.
- GCC idioms: `add rd,rs,#0` moves, interworking returns `pop{rX}; bx rX`, high regs saved as `mov r7,r8; push{r7}`.
- GNU toolchain: libgcc `lib1funcs` `_call_via_rX` and `mov pc,lr` returns; GNU ld `__X_from_thumb` glue
  `bx pc; nop; b` at 0x08047D1C (-> 0x080441E4), 0x08047D44 (-> 0x08043CA0), 0x08047D4C (-> 0x08043C64),
  0x08047D54 (-> 0x08043C3C).

Against the alternatives:

- **ARM SDT/ADS**: no `__rt_` names, no `Image$$` region symbols, no `__16`-prefixed veneers, no armlink-style
  veneers; the glue is GNU ld's. Ruled out for the game code.
- **CodeWarrior GBA**: no `Metrowerks` string or MW runtime names, and the glue/libgcc are GNU's. Very unlikely.

Libraries were built with different flags: Krawall Thumb/ARM code and 0x08044278 onward have no tpcs-frame;
the Krawall ARM routine uses APCS frames (consistent with GCC `-marm -mapcs-frame`). They may be prebuilt `.a` files.

### Candidates (decided in phase 4 by probe + one-function match)

1. **agbcc** (pret, GCC 2.95-era Cygnus thumb backend, open source). First choice. To check: that its
   `-mtpcs-frame` backtrace prologue/epilogue and interworking return match byte for byte.
2. **Open-source GCC 3.x for ARM** (devkitadv / early devkitARM era; the build date is Jan 2005). Fallback if
   agbcc's register allocation or scheduling differs. Also open source.
3. Nintendo's SDK GCC binaries: same lineage as agbcc but proprietary distribution; not to be sourced.

Not settled here: GCC 2.95 vs 3.x (needs a compiled probe), and the exact identity of library functions in
0x08044278-0x080477C0 (Krawall vs SDK vs newlib).
