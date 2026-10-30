void sub_080068F8(void);
void sub_0801A800(void);

extern unsigned short gUnknown_03002C50[];
extern unsigned int gUnknown_03006B14;

void sub_0800554C(unsigned short mode)
{
    *(volatile unsigned short *)0x04000000 = mode | 0x40;
    gUnknown_03002C50[0x80] = 0x100;
    gUnknown_03002C50[0xB2] = 0x100;
    if ((gUnknown_03006B14 & 0x80000) == 0)
        sub_0801A800();
    sub_080068F8();
}
