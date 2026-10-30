extern unsigned char gUnknown_03006B1C[];

int sub_0802CA5C(unsigned int r0)
{
    unsigned int r2 = r0 >> 3;
    unsigned int r1 = r0 & 7;
    unsigned char *r0_ = (unsigned char *)gUnknown_03006B1C;
    r0_ += 0x448;
    return r0_[r2] & (1 << r1);
}
