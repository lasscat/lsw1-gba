void sub_080055AC(unsigned short a)
{
    volatile unsigned short *reg = (volatile unsigned short *)0x04000000;
    *reg = (*reg & 0xFFF8) | a;
}
