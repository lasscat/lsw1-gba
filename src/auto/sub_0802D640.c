extern unsigned char gUnknown_03006B1C[];

void sub_0802D640(void)
{
    unsigned char v;

    v = gUnknown_03006B1C[0x28B];
    if (v == 1)
        return;
    v -= 2;
    if (v <= 1)
        return;
    gUnknown_03006B1C[0x28C] = 1;
}
