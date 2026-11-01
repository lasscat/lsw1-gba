extern unsigned int sub_08017830(void);

unsigned int sub_080175D0(unsigned short arg)
{
    unsigned int threshold;
    threshold = (sub_08017830() & 0x7FFF) * 0x65;
    threshold >>= 15;
    if (arg < threshold)
        return 0;
    return 1;
}
