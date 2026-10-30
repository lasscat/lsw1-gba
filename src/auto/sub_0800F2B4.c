extern unsigned int gUnknown_03003250[];

void sub_0800F2B4(int a, int b, int c, unsigned short d)
{
    if (a <= c) {
        unsigned short *dst = (unsigned short *)gUnknown_03003250[0x1c / 4] + (b * 32 + a);
        int count = (c - a + 1) * 2;
        unsigned short fill = d;
        volatile unsigned int *dma = (volatile unsigned int *)0x040000D4;
        dma[0] = (unsigned int)&fill;
        dma[1] = (unsigned int)dst;
        dma[2] = 0x81000000 | (count >> 1);
        dma[2];
    }
}
