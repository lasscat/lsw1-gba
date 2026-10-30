void sub_08017264(void)
{
    int zero = 0;
    volatile unsigned int *dma = (volatile unsigned int *)0x040000D4;
    dma[0] = (unsigned int)&zero;
    dma[1] = 0x07000000;
    dma[2] = 0x85000100;
    dma[2];
}
