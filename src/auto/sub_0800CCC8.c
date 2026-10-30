extern unsigned char gUnknown_03006B1C[];
extern void sub_08004458(unsigned char, unsigned char);

void sub_0800CCC8(void)
{
    if ((signed char)gUnknown_03006B1C[0x2A2] <= 0)
        return;
    gUnknown_03006B1C[0x2A2]--;
    if (gUnknown_03006B1C[0x2A2] != 0)
        return;
    sub_08004458(gUnknown_03006B1C[0x2A4], gUnknown_03006B1C[0x2A3]);
}
