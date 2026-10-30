void sub_080055E4(unsigned short arg0)
{
    unsigned short r0 = arg0 << 16 >> 16;
    volatile unsigned short *r3 = (volatile unsigned short *)0x04000000;
    *r3 = (*r3 & 0xE0FF) | r0;
}
