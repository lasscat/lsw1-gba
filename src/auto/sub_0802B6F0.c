struct Obj
{
    unsigned char unk00[0x5C];
    unsigned char unk5C;
    unsigned char unk5D[0x83];
    unsigned char unkE0;
    unsigned char unkE1[0x2B];
};

struct T1
{
    unsigned char unk00[0x1C];
    unsigned char unk1C;
    unsigned char unk1D[0x13];
};

struct T2
{
    unsigned char unk00[0x1A];
    unsigned char unk1A;
    unsigned char unk1B[0x05];
};

extern struct T1 gUnknown_0805171C[];
extern struct T2 gUnknown_08051ECC[];

int sub_0802B6F0(struct Obj *obj)
{
    if (obj->unk5C == 0x18) {
        if (gUnknown_0805171C[obj->unkE0].unk1C != 0)
            return 1;
    }
    if (obj->unk5C == 0x19) {
        if (gUnknown_08051ECC[obj->unkE0].unk1A != 0)
            return 1;
    }
    return 0;
}
