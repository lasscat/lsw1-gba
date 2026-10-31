extern void *sub_08004A14(unsigned char arg0, unsigned char arg1);
extern void *sub_08033374(int a, int b);
extern void sub_080144F4(void *p);
extern int sub_0801419C(int x, int y);

struct Entry {
    int unk00;
    unsigned short unk04;
    unsigned short unk06;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
    unsigned char unk0C;
};

struct Pair {
    int x;
    int y;
};

struct Object {
    unsigned char unk00[0x0C];
    struct Pair unk0C;
    struct Pair unk14;
    unsigned char unk1C[0x40 - 0x1C];
    int unk40;
    unsigned char unk44[0x5C - 0x44];
    unsigned char unk5C;
    unsigned char unk5D[0x112 - 0x5D];
    unsigned char unk112;
    unsigned char unk113;
    unsigned char unk114;
};

struct Object *sub_08033210(unsigned char arg0, unsigned char arg1)
{
    struct Entry *entry = sub_08004A14(arg0, arg1);
    struct Object *obj = sub_08033374(0, entry->unk08);

    obj->unk0C.x = entry->unk04 << 16;
    obj->unk0C.y = entry->unk06 << 16;
    sub_080144F4(obj);
    obj->unk14 = obj->unk0C;
    obj->unk112 = entry->unk0A;
    obj->unk113 = entry->unk0A;
    obj->unk114 = entry->unk09;
    obj->unk40 = sub_0801419C(obj->unk0C.x, obj->unk0C.y);
    obj->unk5C = 0x14;
    return obj;
}
