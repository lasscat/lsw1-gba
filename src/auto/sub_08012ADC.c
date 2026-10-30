void sub_08012ADC(void)
{
    volatile unsigned short *r = (volatile unsigned short *)0x04000000;
    unsigned short v = *r;
    *r = v & 0xFF7F;
}
