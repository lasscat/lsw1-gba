extern void sub_0802D914(unsigned char, unsigned char);
extern unsigned char gUnknown_03006B1C[];
extern unsigned char gUnknown_03006F8C[];

void sub_0800DAE8(void *arg)
{
    unsigned char *p = arg;
    sub_0802D914(p[4], p[5]);
    gUnknown_03006B1C[0x2A7] = p[7];
    gUnknown_03006B1C[0x2A8] = p[6];
    if (gUnknown_03006B1C[0x2A6] == 0) {
        gUnknown_03006B1C[0x2A5] = 1;
        gUnknown_03006F8C[5] = 0;
    }
}
