struct Param {
    unsigned char unk00[4];
    unsigned short unk04;
    unsigned short unk06;
    unsigned char unk08;
    unsigned char unk09;
};

struct Entry {
    unsigned char unk00[0x14];
    unsigned int unk14;
    int unk18;
    unsigned short unk1C;
    unsigned char unk1E;
    unsigned char unk1F;
    unsigned char unk20;
    unsigned char unk21;
    unsigned char unk22;
    unsigned char unk23[5];
};

extern unsigned char gUnknown_0300332C[];
extern struct Entry gUnknown_03002DEC[];

void sub_0800BBA4(struct Param *a)
{
    unsigned char i;

    for (i = 0; i < gUnknown_0300332C[0xB8]; i++) {
        gUnknown_03002DEC[i].unk14 = a->unk06 << 16;
        gUnknown_03002DEC[i].unk18 = a->unk04 * 30;
        gUnknown_03002DEC[i].unk22 = 3;
        gUnknown_03002DEC[i].unk1C = 0;
        gUnknown_03002DEC[i].unk20 = a->unk08;
        gUnknown_03002DEC[i].unk21 = a->unk09;
        if (gUnknown_03002DEC[i].unk18 == 0)
            gUnknown_03002DEC[i].unk1E = 1;
        else
            gUnknown_03002DEC[i].unk1E = 0;
    }
}
