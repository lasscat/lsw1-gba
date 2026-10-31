extern void *sub_08004A14(unsigned char arg0, unsigned char arg1);
void *sub_08000234(void);
void sub_08000D7C(void *arg0, int arg1, int arg2);
void sub_0802F400(void);

struct Entry {
    unsigned int unk00;
    unsigned short unk04;
    unsigned short unk06;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
};

struct Object {
    unsigned char unk00[0x58];
    unsigned int unk58;
    unsigned char unk5C;
    unsigned char unk5D[3];
    unsigned int unk60;
    unsigned char unk64[0x7C - 0x64];
    signed char unk7C;
    unsigned char unk7D;
    signed char unk7E;
    unsigned char unk7F;
    unsigned char unk80;
    unsigned char unk81[0x8C - 0x81];
    void (*unk8C)(void);
    unsigned char unk90[0xE1 - 0x90];
    unsigned char unkE1;
    unsigned char unkE2[0xE8 - 0xE2];
    unsigned char unkE8;
    unsigned char unkE9;
};

void *sub_0802F360(unsigned char arg0, unsigned char arg1)
{
    struct Entry *entry = sub_08004A14(arg0, arg1);
    struct Object *object = sub_08000234();

    sub_08000D7C(object, entry->unk04 << 16, entry->unk06 << 16);
    object->unk5C = entry->unk00;
    object->unk58 = 4;
    object->unkE1 = 0;
    object->unk8C = sub_0802F400;
    object->unk7C = -entry->unk08;
    object->unk7E = -entry->unk09;
    object->unk7D = entry->unk08;
    object->unk7F = entry->unk09;
    object->unk80 = 1;
    object->unkE8 = entry->unk0A;
    object->unkE9 = entry->unk0B;
    object->unk60 = 0;
    return object;
}
