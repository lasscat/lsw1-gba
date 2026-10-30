extern unsigned char gUnknown_03006B1C[];
void sub_0800BF14(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);

void sub_0800BEBC(unsigned char *arg0)
{
    unsigned char *p = gUnknown_03006B1C;
    p += 0x2AA;
    sub_0800BF14(p[arg0[4]], arg0[5], p[arg0[6]], arg0[7], arg0[8], arg0[9], arg0[10]);
}
