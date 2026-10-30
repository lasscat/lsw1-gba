void sub_0800E1C4(unsigned short a)
{
    a = (unsigned short)((unsigned int)a << 16 >> 16);
    *(volatile unsigned short *)0x04000000 = (*(volatile unsigned short *)0x04000000 & 0xFFF8) | a;
}
