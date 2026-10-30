extern unsigned short gUnknown_030049D8[];
extern unsigned short gUnknown_030049E0[];

void sub_080186A8(unsigned short a, unsigned short b)
{
    gUnknown_030049D8[0] = (unsigned short)(a << 8);
    gUnknown_030049E0[0] = (unsigned short)(b << 8);
    *(volatile unsigned short *)0x04000052 = (unsigned short)((b << 8) | a);
}
