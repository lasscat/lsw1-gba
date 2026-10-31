extern void sub_080125F8(void);

void sub_08018FA4(unsigned short a)
{
    unsigned short v = 0;
    int d;

    *(volatile unsigned short *)0x04000048 = a;
    *(volatile unsigned short *)0x0400004A = 0x3f - a;
    *(volatile unsigned short *)0x04000040 = 0xf0;
    *(volatile unsigned short *)0x04000044 = 0x8c;
    *(volatile unsigned short *)0x04000000 |= 0x2000;
    *(volatile unsigned short *)0x04000050 = a | 0xc0;
    sub_080125F8();
    *(volatile unsigned short *)0x04000054 = 0;
    do {
        sub_080125F8();
        d = (int)v * 0x10000 + 0x60000;
        v = (unsigned short)((unsigned int)d >> 16);
        *(volatile unsigned short *)0x04000040 = ((d >> 16) << 8) | 0xf0;
    } while ((d >> 16) <= 0xf0);
    *(volatile unsigned short *)0x04000000 &= 0xDFFF;
}
