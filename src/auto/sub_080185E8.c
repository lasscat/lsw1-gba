void sub_080185E8(unsigned short a, unsigned short b)
{
    unsigned short c = b;
    *(volatile unsigned short *)0x04000050 = a | 0xC0;
    if (c > 0x10)
        c = 0x10;
    *(volatile unsigned short *)0x04000054 = c;
}
