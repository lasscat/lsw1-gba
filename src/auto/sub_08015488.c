extern unsigned int gUnknown_03003774;

void sub_08015488(int index)
{
    unsigned char *p = (unsigned char *)gUnknown_03003774;
    int shift = index * 8;
    int bits = 4;
    unsigned char *q;
    p += shift;
    p[1] &= -bits;
    q = (unsigned char *)gUnknown_03003774;
    q += 1024;
    q += shift;
    q[1] &= -bits;
}
