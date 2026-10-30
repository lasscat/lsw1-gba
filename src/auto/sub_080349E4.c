struct O
{
    unsigned char unk00[0x58];
    unsigned int unk58;
    unsigned char unk5C[0x64];
};

void sub_080349E4(struct O *o)
{
    unsigned char *p = (unsigned char *)o;
    int t;
    p += 0xB3;
    t = p[0];
    t &= -0x11;
    p[0] = t;
    p += 2;
    t = p[0];
    t &= -0x0D;
    p[0] = t;
    p += 10;
    p[0] = 0;
    o->unk58 |= 0x20011;
}
