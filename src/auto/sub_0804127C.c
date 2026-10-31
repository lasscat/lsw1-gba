struct UnkStruct_0803F544 {
    unsigned int unk0;
    unsigned int unk4;
    unsigned short unk8;
    unsigned char unkA;
    unsigned char unkB;
    unsigned char unkC;
    unsigned char unkD;
    unsigned char unkE;
};

void sub_0803F544(struct UnkStruct_0803F544 *arg0, unsigned int arg1, unsigned int arg2);

struct Sub4127C_Elem {
    struct UnkStruct_0803F544 *unk0;
    unsigned char unk4[16];
};

struct Sub4127C {
    unsigned char unk0;
    unsigned char unk1;
    unsigned char unk2[2];
    struct Sub4127C_Elem unk4[4];
    unsigned char unk54;
};

void sub_0804127C(struct Sub4127C *arg0)
{
    unsigned int i;

    arg0->unk1 = 0x10;
    arg0->unk0 = 4;
    i = 0;
    while (i < arg0->unk54) {
        sub_0803F544(arg0->unk4[i].unk0, 0x08070304, 2);
        arg0->unk4[i].unk0->unk4 |= 0x02000010;
        i++;
    }
}
