extern void *sub_08004A14(unsigned char arg0, unsigned char arg1);
void *sub_08000234(void);
extern void sub_08002138(void *arg0, unsigned int arg1);
extern void sub_080020FC(void *obj, int val);
extern void sub_08000DA4(void *arg0, int arg1, int arg2);
extern int sub_0801419C(int x, int y);
extern void sub_0803E814(void);
extern unsigned char gUnknown_01000008[];

struct Entry
{
    unsigned int unk00;
    short unk04;
    short unk06;
    unsigned char unk08;
};

struct Node
{
    unsigned char unk00[0x0C];
    int unk0C;
    int unk10;
    unsigned char unk14[0x2C];
    int unk40;
    unsigned char unk44[0x14];
    void *unk58;
    unsigned char unk5C;
    unsigned char unk5D[3];
    void (*unk60)(void);
    unsigned char unk64[0x5B];
    unsigned char unkBF;
    unsigned char unkC0[0x5C];
    unsigned short unk11C;
    unsigned char unk11E[3];
    unsigned char unk121;
    unsigned char unk122;
};

struct Node *sub_0803E774(unsigned char a, unsigned char b)
{
    struct Entry *entry = sub_08004A14(a, b);
    struct Node *node = sub_08000234();
    node->unk5C = entry->unk00;
    node->unk58 = gUnknown_01000008;
    node->unkBF = 0x80;
    sub_08002138(node, 3);
    sub_080020FC(node, 0);
    node->unk60 = sub_0803E814;
    sub_08000DA4(node, entry->unk04, entry->unk06);
    node->unk40 = sub_0801419C(node->unk0C, node->unk10) + 0x960000;
    node->unk121 = entry->unk08;
    node->unk122 = 0;
    node->unk11C = 0;
    return node;
}
