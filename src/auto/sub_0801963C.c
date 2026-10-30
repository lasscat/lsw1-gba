void sub_080125F8(void);

void sub_0801963C(unsigned short r0)
{
    unsigned short r6;
    unsigned short r7;
    unsigned int t;

    r6 = 0x50;
    r7 = 0x50;

    *(volatile unsigned short *)0x04000048 = 0;
    *(volatile unsigned short *)0x0400004A = 0x3f;
    *(volatile unsigned short *)0x04000040 = 0xf0;
    *(volatile unsigned short *)0x04000044 = r6;
    *(volatile unsigned short *)0x04000042 = 0xf0;

    *(volatile unsigned short *)0x04000046 = (unsigned short)((r6 << 8) | 0xa0);

    *(volatile unsigned short *)0x04000000 = (unsigned short)(*(volatile unsigned short *)0x04000000 | 0x6000);

    *(volatile unsigned short *)0x04000050 = (unsigned short)(r0 | 0xc0);

    sub_080125F8();

    *(volatile unsigned short *)0x04000054 = 0;

    do {
        sub_080125F8();
        r6 = (unsigned short)((((unsigned int)r6 << 16) + 0xFFFE0000) >> 16);
        t = ((unsigned int)r7 << 16) + 0x20000;
        *(volatile unsigned short *)0x04000044 = r6;
        r7 = (unsigned short)(t >> 16);
        *(volatile unsigned short *)0x04000046 = (unsigned short)(((int)t >> 8) | 0xa0);
    } while ((int)((unsigned int)r6 << 16) >= 0);

    *(volatile unsigned short *)0x04000000 = (unsigned short)(*(volatile unsigned short *)0x04000000 & 0x9FFF);
}
