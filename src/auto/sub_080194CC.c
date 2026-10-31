void sub_080125F8(void);

static inline unsigned int adv_hi(unsigned short v)
{
    return ((unsigned int)v << 16) + 0x30000;
}

static inline unsigned int adv_lo(unsigned short v)
{
    return ((unsigned int)v << 16) + 0xFFFD0000;
}

void sub_080194CC(unsigned short r0)
{
    unsigned short r5;
    unsigned short r6;
    unsigned int t0;
    unsigned int t1;
    int a;
    int b;
    int c;

    r5 = 0;
    r6 = 0xf0;

    *(volatile unsigned short *)0x04000048 = 0;
    *(volatile unsigned short *)0x0400004A = 0x3f;
    *(volatile unsigned short *)0x04000040 = 0xf0;
    *(volatile unsigned short *)0x04000044 = 0xa0;

    *(volatile unsigned short *)0x04000000 = (unsigned short)(*(volatile unsigned short *)0x04000000 | 0x2000);

    *(volatile unsigned short *)0x04000050 = (unsigned short)(r0 | 0xc0);

    sub_080125F8();

    *(volatile unsigned short *)0x04000054 = 0;

    do {
        sub_080125F8();
        t0 = adv_hi(r5);
        t1 = adv_lo(r6);
        r5 = (unsigned short)(t0 >> 16);
        a = (int)t0 >> 16;
        c = a << 8;
        r6 = (unsigned short)(t1 >> 16);
        b = (int)t1 >> 16;
        *(volatile unsigned short *)0x04000040 = (unsigned short)(b | c);
    } while (a <= 0x77);

    *(volatile unsigned short *)0x04000000 = (unsigned short)(*(volatile unsigned short *)0x04000000 & 0xDFFF);
}
