extern void *sub_08004A14(unsigned char arg0, unsigned char arg1);
void *sub_08000234(void);
void sub_08000D7C(void *arg0, int arg1, int arg2);
extern int sub_0801419C(int x, int y);
extern void sub_0803F140(void);
void sub_0803F058(void *arg0, int arg1);

struct Entry
{
    unsigned int unk00;
    unsigned short unk04;
    unsigned short unk06;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
    unsigned char unk0C;
    unsigned char unk0D;
    unsigned char unk0E;
};

struct Object
{
    unsigned char unk00[0x0C];
    int unk0C;
    int unk10;
    unsigned char unk14[0x2C];
    int unk40;
    unsigned char unk44[0x18];
    unsigned char unk5C;
    unsigned char unk5D[0x0B];
    unsigned int unk68;
    unsigned char unk6C[0x0C];
    unsigned char unk78;
    unsigned char unk79[0x03];
    signed char unk7C;
    unsigned char unk7D;
    signed char unk7E;
    unsigned char unk7F;
    unsigned char unk80;
    unsigned char unk81[0x0B];
    void (*unk8C)(void);
    unsigned char unk90[0x4A];
    unsigned short unkDA;
    unsigned char unkDC[0x1A];
    unsigned char unkF6;
    unsigned char unkF7;
    unsigned char unkF8;
    unsigned char unkF9;
    unsigned char unkFA[0x07];
    unsigned char unk101;
    unsigned char unk102;
    unsigned char unk103;
    unsigned char unk104;
};

struct Object *sub_0803EF80(unsigned char arg0, unsigned char arg1)
{
    struct Entry *entry = sub_08004A14(arg0, arg1);
    struct Object *node = sub_08000234();

    sub_08000D7C(node, entry->unk04 << 16, entry->unk06 << 16);
    node->unk40 = sub_0801419C(node->unk0C, node->unk10);
    node->unk78 = 0x14;
    node->unk5C = entry->unk00;
    node->unkF6 = entry->unk0C;
    node->unkF7 = entry->unk0B;
    node->unkF8 = entry->unk0E;
    node->unkF9 = entry->unk0D;
    node->unk101 = 0;
    node->unk102 = 1;
    node->unk104 = 0;
    node->unkDA = 0;
    node->unk7C = -entry->unk09;
    node->unk7E = -entry->unk0A;
    node->unk7D = entry->unk09;
    node->unk7F = entry->unk0A;
    node->unk80 = 1;
    node->unk8C = sub_0803F140;
    node->unk68 = 0;
    sub_0803F058(node, 1);
    return node;
}
