extern void *sub_08004A14(unsigned char arg0, unsigned char arg1);
void *sub_08000234(void);
void sub_08000D7C(void *arg0, int arg1, int arg2);
int sub_0801419C(int x, int y);
void sub_0801CD4C(void);
void sub_0801CF60(void);

struct Entry {
    unsigned int unk00;
    unsigned short unk04;
    unsigned short unk06;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned char unk0C;
    unsigned char unk0D;
    unsigned char unk0E;
    unsigned char unk0F;
    unsigned char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
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
    signed char unk7C;
    unsigned char unk7D;
    signed char unk7E;
    unsigned char unk7F;
    unsigned char unk80;
    unsigned char unk81[0x8C - 0x81];
    void (*unk8C)(void);
    unsigned char unk90[0xDC - 0x90];
    unsigned short unkDC;
    unsigned char unkDE[0xE1 - 0xDE];
    unsigned char unkE1;
    unsigned char unkE2[0xE8 - 0xE2];
    unsigned short unkE8;
    unsigned short unkEA;
    unsigned char unkEC;
    unsigned char unkED;
    unsigned char unkEE;
    unsigned char unkEF;
    unsigned char unkF0;
};

struct Object *sub_0801CC6C(unsigned char arg0, unsigned char arg1)
{
    struct Entry *entry = sub_08004A14(arg0, arg1);
    struct Object *object = sub_08000234();

    sub_08000D7C(object, entry->unk04 << 16, entry->unk06 << 16);
    object->unk40 = sub_0801419C(object->unk0C, object->unk10);
    object->unkE8 = entry->unk08;
    object->unkEA = entry->unk0A;
    object->unkEF = entry->unk12;
    object->unk5C = entry->unk00;
    object->unk58 = 0x05004004;
    object->unk60 = sub_0801CD4C;
    object->unk8C = sub_0801CF60;
    object->unkE1 = 0;
    object->unkDC = 10;
    object->unkEC = 0;
    object->unk7C = -entry->unk0C;
    object->unk7E = -entry->unk0D;
    object->unk7D = entry->unk0C;
    object->unk7F = entry->unk0D;
    object->unk80 = 1;
    object->unk77 = 1;
    object->unkED = entry->unk0E;
    object->unkEE = entry->unk0F;
    object->unkF0 = entry->unk13;
    return object;
}
