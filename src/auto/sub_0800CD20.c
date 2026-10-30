extern unsigned char gUnknown_03006B1C[];

void sub_0800BF14(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);

void sub_0800CD20(void *arg)
{
    unsigned char *p = arg;
    unsigned char r0 = gUnknown_03006B1C[0x2A2];
    unsigned char r1 = p[4];
    unsigned char r2 = p[5];
    unsigned char r3 = p[6];
    sub_0800BF14(r0, r1, r2, r3, p[7], p[8], p[9]);
}
