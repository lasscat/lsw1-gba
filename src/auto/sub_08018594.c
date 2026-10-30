void sub_08018594(unsigned short *arg0, unsigned int arg1)
{
    unsigned int r3 = (arg1 << 0x1e) >> 0x1e;
    r3 |= arg1 & 0xC;
    r3 |= arg1 & 0x40;
    r3 |= arg1 & 0x80;
    r3 |= (arg1 & 0x1F00);
    r3 |= arg1 & 0x2000;
    r3 |= arg1 & 0xC000;
    *arg0 = (unsigned short)r3;
}
