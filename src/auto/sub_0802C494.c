extern unsigned char gUnknown_03006B1C[];

void sub_0801BDCC(unsigned char);

void sub_0802C494(int value, int flag)
{
    if (flag)
        gUnknown_03006B1C[0x280] = value;

    sub_0801BDCC(value ? 0x80 : 0);
}
