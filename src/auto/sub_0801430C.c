extern unsigned int gUnknown_030049F0;
extern unsigned short gUnknown_03003770;

unsigned short sub_0801430C(unsigned int r0, unsigned int r1)
{
    unsigned int *r4 = (unsigned int *)&gUnknown_03003770;
    unsigned int *r3;
    unsigned int v;
    unsigned int idx;
    unsigned short *p;

    (void)r4;
    r0 >>= 5;
    r1 >>= 5;
    r3 = &gUnknown_030049F0;
    r3 += 0xa3;
    v = *r3;
    v >>= 5;
    idx = r0 + r1 * v;
    idx <<= 1;
    r4 = (unsigned int *)&gUnknown_03003770;
    p = (unsigned short *)((unsigned char *)*r4 + idx);
    return *p;
}
