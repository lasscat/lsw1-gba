extern unsigned short gUnknown_03003430[];

void sub_08011C8C(void);

void sub_08011D48(void)
{
    unsigned short v0;
    unsigned short v1;
    unsigned short t;
    unsigned short a;
    unsigned short b;

    if (gUnknown_03003430[4] != 0) {
        sub_08011C8C();
    } else {
        v0 = gUnknown_03003430[0];
        gUnknown_03003430[1] = v0;
        v1 = *(volatile unsigned short *)0x04000130;
        v1 ^= 0x3FF;
        gUnknown_03003430[0] = v1;
        gUnknown_03003430[6] = v0;
        gUnknown_03003430[5] = v1;
        t = v1 ^ v0;
        a = t & v1;
        gUnknown_03003430[7] = a;
        b = v0 & t;
        gUnknown_03003430[8] = b;
        gUnknown_03003430[2] = a;
        gUnknown_03003430[3] = b;
    }
}
