typedef struct
{
    unsigned int sad;
    unsigned int dad;
    unsigned int cnt;
} Dma3Regs;

void sub_08017220(void)
{
    unsigned short v;
    unsigned short *src = &v;
    volatile Dma3Regs *dma;
    *src = 0;
    dma = (volatile Dma3Regs *)0x040000D4;
    dma->sad = (unsigned int)src;
    dma->dad = 0x06000000;
    dma->cnt = 0x8100C000;
    (void)dma->cnt;
}
