extern unsigned char gUnknown_03006B1C[];

unsigned int sub_0802CC4C(int arg0)
{
    unsigned char *r2;
    unsigned int r1;
    r2 = gUnknown_03006B1C;
    r1 = 0x295;
    r2 = r2 + r1;
    r1 = 1;
    r1 = r1 << arg0;
    r1 = r1 & *r2;
    return r1;
}
