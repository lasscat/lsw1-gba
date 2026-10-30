extern unsigned int gUnknown_03006B14;
extern unsigned int gUnknown_0300368C;

void sub_080004F8(void);

void sub_08024D20(void)
{
    if (gUnknown_03006B14 & 0x80000)
    {
        sub_080004F8();
        gUnknown_03006B14 |= 8;
    }
    {
        unsigned int *r1 = &gUnknown_0300368C;
        r1[1] = 2;
    }
}
