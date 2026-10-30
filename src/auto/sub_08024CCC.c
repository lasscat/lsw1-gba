extern unsigned char gUnknown_0300332C[];
extern unsigned char gUnknown_03006A00[];
extern unsigned int gUnknown_03006B14;

int sub_08024CCC(void)
{
    if (gUnknown_0300332C[0xB8] > 1u)
    {
        gUnknown_03006A00[7]++;
        gUnknown_03006B14 &= 0xFFFEFFFF;
        gUnknown_03006B14 &= 0xFFFDFFFF;
    }
    return 0;
}
