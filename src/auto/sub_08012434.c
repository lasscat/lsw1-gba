void CpuSet(const void *src, void *dest, unsigned int count);

extern unsigned int gUnknown_030034DC[];
extern unsigned int gUnknown_030034A8[];
extern unsigned int gUnknown_03007FFC;

void sub_08012434(const void *src)
{
    unsigned short saved;

    // FAKE: local volatile cast keeps the saved MMIO value in a stack slot, as in the original
    *(volatile unsigned short *)&saved = *(volatile unsigned short *)0x04000208;
    *(volatile unsigned short *)0x04000208 = 0;
    CpuSet(src, gUnknown_030034DC, 0x04000064);
    gUnknown_03007FFC = (unsigned int)gUnknown_030034DC;
    CpuSet((const void *)0x0804B9D0, gUnknown_030034A8, 0x0400000D);
    // FAKE: local volatile cast keeps the saved MMIO value in a stack slot, as in the original
    *(volatile unsigned short *)0x04000208 = *(volatile unsigned short *)&saved;
}
