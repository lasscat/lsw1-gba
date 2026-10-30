extern unsigned char *gUnknown_03002BFC;
extern void sub_080045D8(unsigned int, unsigned int);

void sub_08005308(unsigned int arg0, unsigned int arg1)
{
    unsigned char *base = gUnknown_03002BFC;
    unsigned int s0 = arg0 * 2;
    unsigned char *q = base + 2;
    unsigned short off = *(unsigned short *)(q + s0);
    unsigned char *p = base + off;
    unsigned int s1 = arg1 * 8 + 4;
    unsigned int v;
    p += s1;
    v = p[4];
    if (v != 0)
        sub_080045D8(v, 0);
}
