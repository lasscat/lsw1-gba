void sub_08005648(unsigned short a)
{
    *(volatile unsigned short *)0x04000000 |= a;
}
