extern unsigned char gUnknown_03002EC4[];
extern unsigned int gUnknown_03002F24;

void sub_0800A1A8(unsigned char a, int b)
{
    unsigned char *p = gUnknown_03002EC4 + (a << 3);
    *p &= 0xFE;
    gUnknown_03002F24 &= ~(1 << a);
    if (b) {
        p[4] = p[3];
        *p |= 2;
    }
}
