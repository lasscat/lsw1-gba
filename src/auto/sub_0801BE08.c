extern unsigned char gUnknown_03006B1C[];
extern void sub_08046784(unsigned int, unsigned int);

void sub_0801BE08(unsigned char arg)
{
    unsigned char b = arg & 0xFF;
    sub_08046784(b, 0);
    gUnknown_03006B1C[0x281] = b;
}
