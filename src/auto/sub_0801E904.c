extern void *sub_08004A14(unsigned char arg0, unsigned char arg1);
void *sub_08000234(void);
void sub_0801E96C(void);

struct Entry {
    unsigned char unk00[8];
    unsigned short unk08;
    unsigned char unk0A;
    unsigned char unk0B;
};

struct Object {
    unsigned char unk00[0x58];
    unsigned int unk58;
    unsigned char unk5C;
    unsigned char unk5D[3];
    void (*unk60)(void);
    unsigned char unk64[0xEC - 0x64];
    unsigned short unkEC;
    unsigned char unkEE[0xF4 - 0xEE];
    unsigned char unkF4;
    unsigned char unkF5;
};

void *sub_0801E904(unsigned char arg0, unsigned char arg1)
{
    struct Entry *entry = sub_08004A14(arg0, arg1);
    struct Object *object = sub_08000234();

    object->unk58 = 8;
    object->unkF4 = entry->unk0A;
    object->unkF5 = entry->unk0B;
    object->unkEC = entry->unk08 * 30;
    object->unk60 = sub_0801E96C;
    object->unk5C = 14;
    return object;
}
