extern void sub_080125F8(void);

void sub_08018D30(unsigned short a)
{
    unsigned short v = 0;
    unsigned int t;
    int s;

    *(volatile unsigned short *)0x04000048 = 0;
    *(volatile unsigned short *)0x0400004A = 0x3f;
    *(volatile unsigned short *)0x04000040 = 0xf0;
    *(volatile unsigned short *)0x04000044 = 0xa0;
    *(volatile unsigned short *)0x04000000 |= 0x2000;
    *(volatile unsigned short *)0x04000050 = a | 0xc0;
    sub_080125F8();
    *(volatile unsigned short *)0x04000054 = 0;
    do {
        sub_080125F8();
        t = (unsigned int)v * 0x10000 + 0x20000;
        v = (unsigned short)(t >> 16);
        s = (int)t >> 16;
        *(volatile unsigned short *)0x04000044 = (s << 8) | 0xa0;
    } while (s <= 0xa0);
    *(volatile unsigned short *)0x04000000 &= 0xDFFF;
}
