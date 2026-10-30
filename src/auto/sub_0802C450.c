extern unsigned char gUnknown_03006B1C[];
void sub_0801BE08(unsigned char arg);

void sub_0802C450(int a, int b)
{
    if (b != 0)
        gUnknown_03006B1C[0x281] = a;
    sub_0801BE08(a != 0 ? 0xFF : 0);
}
