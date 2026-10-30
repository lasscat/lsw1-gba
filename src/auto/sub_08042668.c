extern unsigned char gUnknown_0300332C[];
extern unsigned char gUnknown_03006B1C[];
extern void sub_080426DC(void);

void sub_08042668(void)
{
    unsigned int *p;

    gUnknown_0300332C[0xCD] = 7;
    gUnknown_0300332C[0xCE] = 0x18;
    p = (unsigned int *)(gUnknown_0300332C + 0x8C);
    *p &= -0x98;
    if (gUnknown_03006B1C[0x445] == 0) {
        sub_080426DC();
    } else {
        *(unsigned short *)(gUnknown_03006B1C + 0x3B0) = 0;
        *(unsigned short *)(gUnknown_03006B1C + 0x3B2) = 0;
        *(unsigned short *)(gUnknown_03006B1C + 0x3B4) = 0;
    }
}
