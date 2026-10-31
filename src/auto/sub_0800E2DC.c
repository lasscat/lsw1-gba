extern void *sub_08004A14(unsigned char arg0, unsigned char arg1);
extern void *sub_08000234(void);
extern void sub_08000DA4(void *arg0, int arg1, int arg2);
extern int sub_0801419C(int x, int y);
extern void sub_0800E410(unsigned char a0, int a1, int a2, unsigned char a3);
extern void sub_0800E508(int a, int b);
extern void sub_0800E534(int a, int b);
extern void sub_0800E390(void);

struct Entry {
    int unk00;
    short unk04;
    short unk06;
    unsigned char unk08;
    unsigned char unk09;
};

struct Object {
    unsigned char unk00[0x0C];
    int unk0C;
    int unk10;
    unsigned char unk14[0x40 - 0x14];
    int unk40;
    unsigned char unk44[0x58 - 0x44];
    int unk58;
    unsigned char unk5C;
    unsigned char unk5D[0x60 - 0x5D];
    void (*unk60)(void);
    unsigned char unk64[0xD4 - 0x64];
    int unkD4;
    unsigned char unkD8[0xE8 - 0xD8];
    int unkE8;
};

void *sub_0800E2DC(unsigned char arg0, unsigned char arg1)
{
    struct Entry *entry = sub_08004A14(arg0, arg1);
    struct Object *obj = sub_08000234();
    unsigned char unk09;

    sub_08000DA4(obj, entry->unk04, entry->unk06);
    obj->unk40 = sub_0801419C(obj->unk0C, obj->unk10);
    obj->unk5C = entry->unk00;
    obj->unk58 = 0x4008;
    obj->unkD4 |= 0x80;
    sub_0800E410(entry->unk08, entry->unk04, entry->unk06, 0);
    unk09 = entry->unk09;
    if (unk09 == 0) {
        sub_0800E508(entry->unk04, entry->unk06);
        obj->unkE8 = unk09;
    } else {
        sub_0800E534(entry->unk04, entry->unk06);
        obj->unkE8 = 1;
    }
    obj->unk60 = sub_0800E390;
    return obj;
}
