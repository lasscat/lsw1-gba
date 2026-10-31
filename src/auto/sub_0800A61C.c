extern unsigned char gUnknown_03003190[];

unsigned int sub_0800A61C(unsigned short a)
{
    unsigned char *s = gUnknown_03003190;
    unsigned int i0 = a & 0x1F;
    unsigned char *t = s + 16;
    unsigned char *p0 = t + i0;
    unsigned int i1 = (a & 0x3E0) >> 5;
    unsigned char *p1 = t + i1;
    unsigned int i2 = (a & 0x7C00) >> 10;
    unsigned char *p2 = t + i2;
    return (*p0 & 0x1F) | ((*p1 << 5) & 0x3E0) | ((*p2 << 10) & 0x7C00);
}
