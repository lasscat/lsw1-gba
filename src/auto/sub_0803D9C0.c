extern void *sub_08004A14(unsigned char arg0, unsigned char arg1);
void *sub_08000234(void);
void sub_08000D7C(void *arg0, int arg1, int arg2);
extern int sub_0801419C(int x, int y);
void sub_0803DCD4(void);
void sub_0803DBE0(void);
void sub_0803DDB0(void);

struct Entry {
    unsigned int unk00;
    unsigned short unk04;
    unsigned short unk06;
};


struct Vec {
    int x;
    int y;
};

struct Object {
    unsigned char unk00[0x0C];
    int unk0C;
    int unk10;
    unsigned char unk14[0x40 - 0x14];
    int unk40;
    unsigned char unk44[0x58 - 0x44];
    unsigned int unk58;
    unsigned char unk5C;
    unsigned char unk5D[3];
    void (*unk60)(void);
    unsigned char unk64[0x77 - 0x64];
    unsigned char unk77;
    unsigned char unk78[0x7C - 0x78];
    struct Vec unk7C;
    struct Vec unk84;
    void (*unk8C)(void);
    void (*unk90)(void);
    unsigned char unk94[0xD4 - 0x94];
    unsigned int unkD4;
    unsigned char unkD8[0xE0 - 0xD8];
    unsigned char unkE0;
    unsigned char unkE1;
};

void *sub_0803D9C0(unsigned char arg0, unsigned char arg1)
{
    struct Entry *entry = sub_08004A14(arg0, arg1);
    struct Object *object = sub_08000234();

    sub_08000D7C(object, entry->unk04 << 16, entry->unk06 << 16);
    object->unk5C = entry->unk00;
    object->unk58 = 0x4004;
    object->unkD4 |= 0x80;
    object->unkE1 = 0;
    object->unk8C = sub_0803DCD4;
    object->unk60 = sub_0803DBE0;
    object->unk40 = sub_0801419C(object->unk0C, object->unk10);
    if (object->unkE0 == 2) {
        object->unk84 = object->unk7C;
        object->unk77 = 2;
        object->unk90 = sub_0803DDB0;
    }
    return object;
}
