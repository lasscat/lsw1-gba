extern unsigned int gUnknown_03002E14[];

void sub_08007A08(unsigned short a, unsigned short b, unsigned short c, unsigned short d)
{
    gUnknown_03002E14[0x20 / 4] = a;
    gUnknown_03002E14[0x24 / 4] = b;
    gUnknown_03002E14[0x28 / 4] = c;
    gUnknown_03002E14[0x2c / 4] = d;
}
