extern unsigned int gUnknown_03004964;
extern unsigned int gUnknown_03004968;
extern unsigned int gUnknown_0300496C;
extern unsigned int gUnknown_0300497C;

void sub_08017614(unsigned int arg0);

void sub_080173B4(unsigned int arg0)
{
    gUnknown_0300497C = arg0;
    sub_08017614(arg0);
    gUnknown_0300496C = 0x26F;
    gUnknown_03004968 = gUnknown_03004964 + 4;
}
