void sub_080125F8(void);

void sub_08019420(unsigned short r0)
{
    unsigned short r6;
    unsigned short r5;
    unsigned int d;
    unsigned int u;
    short a;
    short b;
    int s;

    r6 = 0x78;
    *(volatile unsigned short *)0x04000048 = 0;
    *(volatile unsigned short *)0x0400004A = 0x3f;
    r5 = 0x78;
    *(volatile unsigned short *)0x04000040 = (r6 << 8) | r5;
    *(volatile unsigned short *)0x04000044 = 0xa0;
    *(volatile unsigned short *)0x04000000 = (unsigned short)(*(volatile unsigned short *)0x04000000 | 0x2000);
    *(volatile unsigned short *)0x04000050 = (unsigned short)(r0 | 0xc0);
    do {
        sub_080125F8();
        d = ((unsigned int)r6 << 16) + 0xFFFD0000;
        u = ((unsigned int)r5 << 16) + 0x30000;
        r6 = (unsigned short)(d >> 16);
        a = (int)d >> 16;
        s = a << 8;
        r5 = (unsigned short)(u >> 16);
        b = (int)u >> 16;
        *(volatile unsigned short *)0x04000040 = (unsigned short)((s | b));
    } while (a >= 0);
    *(volatile unsigned short *)0x04000054 = 0x10;
    *(volatile unsigned short *)0x04000000 = (unsigned short)(*(volatile unsigned short *)0x04000000 & 0xDFFF);
}
