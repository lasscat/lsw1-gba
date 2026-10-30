extern void *sub_08012BDC(void *, void *, int);
extern char gUnknown_03004934[];

void *sub_080160BC(void)
{
    void *r0;
    void *r4;
    void *r1;
    void *r2;
    unsigned short r3;

    r0 = gUnknown_03004934;
    r4 = r0 - 0x14;
    r2 = sub_08012BDC(r0, r4, 0x5c);
    r1 = (void *)(*(unsigned short *)(r4 + 0x20) + 1);
    *(unsigned short *)(r4 + 0x20) = (unsigned short)r1;
    r0 = (void *)((unsigned int)(unsigned short)r1 << 16);
    r0 = (void *)((unsigned int)r0 >> 16);
    r3 = *(unsigned short *)(r4 + 0x22);
    if ((unsigned short)r0 > r3) {
        *(unsigned short *)(r4 + 0x22) = (unsigned short)r1;
    }
    r0 = r2;
    return r0;
}
