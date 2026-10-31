extern unsigned char gUnknown_03002BE0[];
extern unsigned char gUnknown_0300332C[];
extern unsigned int gUnknown_0300368C;
extern unsigned char gUnknown_03006B1C[];
extern void sub_080425F0(unsigned int);

struct Row {
    unsigned char unk0[6];
    unsigned char unk6;
    unsigned char unk7;
};

void sub_0804256C(void)
{
    struct Row *t;
    unsigned char *d;
    gUnknown_0300332C[0xBF] = 0;
    d = &gUnknown_03002BE0[0];
    t = (struct Row *)0x080716E0;
    *d = t[gUnknown_03006B1C[0x293]].unk6;
    gUnknown_0300332C[0xB7] = t[gUnknown_03006B1C[0x293]].unk7;
    gUnknown_03006B1C[0x299] = t[gUnknown_03006B1C[0x293]].unk7;
    if (gUnknown_0300368C != 0x11)
        sub_080425F0(gUnknown_03006B1C[0x293]);
}
