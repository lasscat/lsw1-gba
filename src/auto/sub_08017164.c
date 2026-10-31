extern unsigned int gUnknown_0804C004;
extern unsigned int gUnknown_0804C000;
extern unsigned int gUnknown_0804C00C;
extern unsigned int gUnknown_0804C008;

void sub_08017164(void)
{
    unsigned int v1;
    unsigned int v2;
    volatile unsigned int *dma;
    int zero;
    v1 = gUnknown_0804C004 - gUnknown_0804C000;
    v2 = gUnknown_0804C00C - gUnknown_0804C008;
    zero = 0;
    dma = (volatile unsigned int *)0x040000D4;
    dma[0] = (unsigned int)&zero;
    dma[1] = v1 + 0x03000000;
    dma[2] = 0x85000000 | ((0x7E00 - v1) >> 2);
    dma[2];
    zero = 0;
    dma[0] = (unsigned int)&zero;
    dma[1] = v2 + 0x02000000;
    dma[2] = 0x85000000 | ((0x40000 - v2) >> 2);
    dma[2];
}
