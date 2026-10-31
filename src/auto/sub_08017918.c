extern unsigned char sub_0801D084(void);
extern unsigned char gUnknown_03004980[];

void sub_08017918(void)
{
    gUnknown_03004980[0x0a] = sub_0801D084();
    gUnknown_03004980[0x0b] = 1;
}
