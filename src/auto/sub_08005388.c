void sub_0800554C(unsigned short mode);
extern void *sub_080135D0(int);
extern unsigned char gUnknown_03002C50[];

void sub_08005388(void)
{
    int i;
    int off;
    unsigned int *p;
    unsigned int base;
    void **slot;
    sub_0800554C(0);
    p = (unsigned int *)gUnknown_03002C50;
    *p++ = 0;
    off = 0;
    base = (unsigned int)p;
    for (i = 3; i >= 0; i--) {
        slot = (void **)(off + base + 8);
        *slot = sub_080135D0(0x800);
        off += 100;
    }
}
