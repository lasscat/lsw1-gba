extern void *sub_08004A14(unsigned char arg0, unsigned char arg1);
void *sub_08000234(void);
extern void sub_08002138(void *arg0, unsigned int arg1);
extern void sub_080020FC(void *obj, int val);
extern void sub_08000DA4(void *arg0, int arg1, int arg2);
extern int sub_0801419C(int x, int y);
extern void sub_080144F4(void *arg0);
extern void sub_0803D86C(void);
extern unsigned char gUnknown_01000008[];

struct Entry
{
    unsigned int unk00;
    short unk04;
    short unk06;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
    unsigned char unk0C;
    unsigned char unk0D;
};

struct Node
{
    unsigned char unk00[0x0C];
    int unk0C;
    int unk10;
    unsigned char unk14[0x40 - 0x14];
    int unk40;
    unsigned char unk44[0x58 - 0x44];
    void *unk58;
    unsigned char unk5C;
    unsigned char unk5D[3];
    void (*unk60)(void);
    unsigned char unk64[0xBF - 0x64];
    unsigned char unkBF;
    unsigned char unkC0[0xE8 - 0xC0];
    unsigned int unkE8;
    unsigned char unkEC[0xF0 - 0xEC];
    unsigned char unkF0;
    unsigned char unkF1;
    unsigned char unkF2[2];
    unsigned char unkF4;
    unsigned char unkF5;
    unsigned char unkF6;
    unsigned char unkF7[0x100 - 0xF7];
    unsigned char unk100;
    unsigned char unk101;
    unsigned char unk102[2];
    unsigned char unk104;
    unsigned char unk105;
    unsigned char unk106;
    unsigned char unk107;
    unsigned short unk108;
    unsigned char unk10A[2];
    unsigned int unk10C;
    unsigned int unk110;
};

struct Node *sub_0803D784(unsigned char a, unsigned char b)
{
    struct Entry *entry = sub_08004A14(a, b);
    struct Node *node = sub_08000234();
    node->unk5C = entry->unk00;
    node->unk58 = gUnknown_01000008;
    node->unkBF = 0x80;
    sub_08002138(node, 3);
    sub_080020FC(node, 0);
    node->unkF1 = 0;
    node->unkF0 = 0;
    node->unk100 = 0;
    node->unkF6 = 0x2D;
    node->unk60 = sub_0803D86C;
    node->unkF4 = 0;
    sub_08000DA4(node, entry->unk04, entry->unk06);
    node->unk40 = sub_0801419C(node->unk0C, node->unk10);
    sub_080144F4(node);
    node->unk101 = entry->unk09;
    node->unk104 = entry->unk0B;
    node->unk105 = entry->unk0A;
    node->unkE8 = 0;
    node->unk106 = entry->unk0C;
    node->unk108 = entry->unk0D;
    node->unk110 = 0;
    node->unk10C = 0;
    return node;
}
