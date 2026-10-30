extern unsigned short gUnknown_04000048;
extern unsigned short gUnknown_0400004A;

void sub_0801EC48(unsigned short a, unsigned short b, unsigned short c)
{
    gUnknown_04000048 = a | (b << 8);
    gUnknown_0400004A = (gUnknown_0400004A & 0xFF00) | c;
}
