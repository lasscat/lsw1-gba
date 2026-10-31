extern unsigned char gUnknown_0300332C[];
extern void sub_0802D810(unsigned char *, signed char, unsigned char *);

void sub_0800D994(unsigned char *a0)
{
    unsigned char buf[8];
    unsigned char *p;
    buf[0] = gUnknown_0300332C[0xC0];
    buf[1] = gUnknown_0300332C[0xC1];
    buf[2] = gUnknown_0300332C[0xC2];
    buf[3] = gUnknown_0300332C[0xC3];
    p = buf + 4;
    p[0] = a0[8];
    p[1] = a0[9];
    p[2] = 0x69;
    p[3] = 0x69;
    sub_0802D810(buf, ((signed char *)gUnknown_0300332C)[0xBF], p);
}
