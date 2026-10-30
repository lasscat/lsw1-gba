extern unsigned int gUnknown_0300366C;

void sub_080123E8(void)
{
    *(volatile unsigned short *)0x04000200 = 0x11;
    *(volatile unsigned short *)0x04000004 = 8;
    gUnknown_0300366C &= ~1;
    *(volatile unsigned short *)0x04000208 = 1;
}
