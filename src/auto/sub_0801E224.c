void sub_0801E224(void)
{
    *(volatile unsigned short *)0x04000200 = *(volatile unsigned short *)0x04000200 & 0xFFFB;
    *(volatile unsigned short *)0x04000202 = *(volatile unsigned short *)0x04000202 | 4;
    *(volatile unsigned short *)0x04000004 = *(volatile unsigned short *)0x04000004 & 0xDF;
}
