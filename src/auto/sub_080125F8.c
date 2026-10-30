extern unsigned int gUnknown_0300366C;

void VBlankIntrWait(void);

void sub_080125F8(void)
{
    gUnknown_0300366C &= -2;
    VBlankIntrWait();
}
