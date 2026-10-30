void sub_0801C5AC(void)
{
    *(volatile unsigned short *)0x04000208 = 0;
    *(volatile unsigned short *)0x04000200 |= 0x10;
    *(volatile unsigned short *)0x04000208 = 1;
}
