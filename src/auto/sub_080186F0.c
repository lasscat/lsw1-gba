extern unsigned short gUnknown_030049D8[];
extern unsigned short gUnknown_030049E0[];

void sub_080186F0(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3)
{
    gUnknown_030049D8[2] = (unsigned short)(r0 << 8);
    gUnknown_030049D8[3] = (unsigned short)(r1 << 8);
    gUnknown_030049E0[2] = (unsigned short)(r2 << 8);
    gUnknown_030049E0[3] = (unsigned short)(r3 << 8);
}
