void sub_0800E1FC(unsigned short a)
{
    *(volatile unsigned short *)0x04000000 = (*(volatile unsigned short *)0x04000000 & 7) | (a & 0xFFFF);
}
