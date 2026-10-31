struct Param {
    unsigned char unk00[4];
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    short unk08;
    unsigned short unk0A;
};

struct Pair {
    unsigned int unk00;
    unsigned int unk04;
};

struct Obj {
    unsigned char unk00[0x24];
    struct Pair unk24;
    unsigned char unk2C[0xB6];
    unsigned char unkE2;
};

struct Entry {
    struct Obj *unk00;
    struct Pair unk04;
    unsigned char unk0C[8];
    unsigned int unk14;
    int unk18;
    unsigned short unk1C;
    unsigned char unk1E;
    unsigned char unk1F;
    unsigned char unk20;
    unsigned char unk21;
    unsigned char unk22;
    unsigned char unk23;
    unsigned char unk24;
    unsigned char unk25;
    unsigned char unk26[2];
};

extern unsigned char gUnknown_0300332C[];
extern struct Entry gUnknown_03002DEC[];
extern unsigned int gUnknown_030031C4;
extern unsigned int sub_08004A5C(unsigned char, unsigned char);
extern int sub_080133A0(short a);

void sub_0800B9F0(struct Param *a)
{
    struct Obj *obj = *(struct Obj **)(gUnknown_0300332C + gUnknown_0300332C[0xB9] * 0x7C);

    if (sub_08004A5C(a->unk04, a->unk05) == 0)
        return;
    if (gUnknown_030031C4 == 1)
        gUnknown_030031C4 = 2;
    if (gUnknown_030031C4 == 2)
        gUnknown_03002DEC[gUnknown_0300332C[0xB9]].unk25 = 1;
    gUnknown_03002DEC[gUnknown_0300332C[0xB9]].unk14 = sub_080133A0(a->unk08);
    gUnknown_03002DEC[gUnknown_0300332C[0xB9]].unk1C = a->unk0A;
    gUnknown_03002DEC[gUnknown_0300332C[0xB9]].unk00 = obj;
    gUnknown_03002DEC[gUnknown_0300332C[0xB9]].unk20 = a->unk06;
    gUnknown_03002DEC[gUnknown_0300332C[0xB9]].unk21 = a->unk07;
    gUnknown_03002DEC[gUnknown_0300332C[0xB9]].unk23 = obj->unkE2;
    gUnknown_03002DEC[gUnknown_0300332C[0xB9]].unk04 = obj->unk24;
    gUnknown_03002DEC[gUnknown_0300332C[0xB9]].unk24 = 0;
    obj->unk24.unk00 = 0;
    obj->unk24.unk04 = 0;
    gUnknown_03002DEC[gUnknown_0300332C[0xB9]].unk22 = 1;
}
