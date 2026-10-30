extern void sub_080125F8(void);

/* Closes the window 1 right edge from 0xa0 down to 0, two pixels per frame. */
void sub_08018E68(unsigned short a)
{
    unsigned short v = 0xa0;

    *(volatile unsigned short *)0x04000048 = 0;
    *(volatile unsigned short *)0x0400004A = 0x3f;
    *(volatile unsigned short *)0x04000040 = 0xf0;
    *(volatile unsigned short *)0x04000044 = v;
    *(volatile unsigned short *)0x04000000 |= 0x2000;
    *(volatile unsigned short *)0x04000050 = a | 0xc0;
    sub_080125F8();
    *(volatile unsigned short *)0x04000054 = 0;
    do {
        sub_080125F8();
        v = (unsigned short)(((unsigned int)v * 0x10000 + 0xFFFE0000) >> 16);
        *(volatile unsigned short *)0x04000044 = v;
    } while ((signed short)v >= 0);
    *(volatile unsigned short *)0x04000000 &= 0xDFFF;
}
