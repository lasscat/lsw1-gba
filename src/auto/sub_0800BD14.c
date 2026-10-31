void sub_08013DEC(unsigned int arg0, unsigned int arg1, unsigned int arg2);

extern unsigned char gUnknown_030033E3[];
extern unsigned int gUnknown_030036A4[];
extern unsigned char gUnknown_03006B1C[];
extern unsigned int gUnknown_03006B14;

void sub_0800BD14(unsigned char *arg0)
{
    unsigned char i = 0;
    unsigned int v;

    do
    {
        gUnknown_030033E3[i] = arg0[5];
        i++;
    } while (i == 0);
    sub_08013DEC(15, arg0[6], 0);
    gUnknown_030036A4[3] = arg0[4];
    gUnknown_03006B1C[0x28F] = arg0[4];
    v = gUnknown_03006B14;
    if ((v & 1) != 0)
    {
        gUnknown_03006B14 = v & ~1;
    }
}
