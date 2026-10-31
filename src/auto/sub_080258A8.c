extern unsigned char gUnknown_03004980[];
extern unsigned char gUnknown_03006AD4[];
extern unsigned int gUnknown_03006B14;

void sub_080258A8(void)
{
    unsigned char *p = gUnknown_03004980;
    unsigned char *q = gUnknown_03006AD4;
    unsigned int v = q[3];
    int s = (v & 1) << 6;
    int m = p[13] & ~0x40;

    p[13] = m | s;
    v <<= 24;
    if (v == 0)
        gUnknown_03006B14 &= ~0x400;
    else
        gUnknown_03006B14 |= 0x400;
}
