extern unsigned char gUnknown_03002E14[];

void sub_08007B04(int a, unsigned char b, unsigned char c)
{
    int base = (int)gUnknown_03002E14;
    int addr = base + a * 0x54;
    *(unsigned char *)(addr + 0x50) = b;
    *(unsigned char *)(addr + 0x51) = c;
}
