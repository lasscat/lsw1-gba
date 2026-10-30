extern unsigned char gUnknown_03002E14[];

signed char sub_08007B3C(int a)
{
    int base = (int)gUnknown_03002E14;
    return (signed char)*(unsigned char *)(base + a * 0x54 + 0x50);
}
