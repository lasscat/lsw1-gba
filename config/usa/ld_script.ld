/* Linker script for the LSW1 GBA ROM (phase 3: all-asm rebuild).
 *
 * Objects come in ROM order on the command line (asm/manifest.txt order, written by tools/configure.py);
 * `*(.text)` keeps that order. Segments (config/usa/layout.txt):
 *   .text   ROM code and data, run in place at 0x08000000
 *   .iwram  linked at 0x03000000, stored in the ROM right after .text (crt0 copies it)
 *   .ewram  linked at 0x02000000, stored right after .iwram
 * objcopy writes the image from 0x08000000 and pads it to 16 MiB with 0x00.
 */
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)

SECTIONS
{
    .text 0x08000000 :
    {
        *(.text)
        *(.glue_7t) *(.glue_7) *(.vfp11_veneer) *(.v4_bx)
    }
    __rom_end = LOADADDR(.text) + SIZEOF(.text);

    .iwram 0x03000000 : AT(__rom_end)
    {
        *(.iwram)
    }
    __iwram_lma_end = LOADADDR(.iwram) + SIZEOF(.iwram);

    .ewram 0x02000000 : AT(__iwram_lma_end)
    {
        *(.ewram)
    }

    /* The asm uses none of these; they must stay empty or the image would change. */
    .data (NOLOAD) : { *(.data) }
    .bss (NOLOAD) : { *(.bss) }
    ASSERT(SIZEOF(.data) == 0 && SIZEOF(.bss) == 0, "unexpected .data/.bss contents")

    .ARM.attributes 0 : { *(.ARM.attributes) }
    /DISCARD/ : { *(.note.*) *(.comment) }
}
