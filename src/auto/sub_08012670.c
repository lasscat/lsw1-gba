void sub_08012670(void)
{
    *(volatile unsigned short *)0x04000200 = *(volatile unsigned short *)0x04000200 & 0xFFFB;
    *(volatile unsigned short *)0x04000004 = *(volatile unsigned short *)0x04000004 & 0xFFDF;
}
