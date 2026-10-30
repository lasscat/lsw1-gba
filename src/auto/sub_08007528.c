extern unsigned char gUnknown_03002C54[];

void sub_08007528(int a, unsigned short b, unsigned short c)
{
    unsigned char *p = gUnknown_03002C54 + a * 100;
    *(unsigned short *)(p + 0x60) = b;
    *(unsigned short *)(p + 0x62) = c;
}
