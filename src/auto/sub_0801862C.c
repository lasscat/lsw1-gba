void sub_0801862C(unsigned short a, unsigned short b)
{
    *(volatile unsigned short *)0x04000050 = a | 0x80;
    if (b > 0x10)
        b = 0x10;
    *(volatile unsigned short *)0x04000054 = b;
}
