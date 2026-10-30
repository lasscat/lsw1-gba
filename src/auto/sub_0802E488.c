extern unsigned char gUnknown_03006B1C[];

void sub_0802E488(int arg)
{
    unsigned char *p = gUnknown_03006B1C;

    if (*(unsigned short *)(p + 0x3B0) + arg > 999)
        arg = 999 - *(unsigned short *)(p + 0x3B0);
    *(unsigned int *)(p + 0x3AC) += arg;
    *(unsigned short *)(p + 0x3B0) += arg;
}
