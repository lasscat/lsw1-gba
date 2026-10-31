extern void *sub_08004A14(unsigned char arg0, unsigned char arg1);
void *sub_08000234(void);
extern void sub_08002138(void *arg0, unsigned int arg1);
extern void sub_080020FC(void *obj, int val);
extern void sub_08000DA4(void *arg0, int arg1, int arg2);
extern int sub_0801419C(int x, int y);
extern void sub_080144F4(void *arg0);
extern unsigned int sub_08004A5C(unsigned char arg0, unsigned char arg1);
extern unsigned char gUnknown_05000008[];
void sub_0803C91C(void);

struct Entry {
    unsigned int unk00;
    short unk04;
    short unk06;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
    unsigned char unk0C;
    unsigned char unk0D;
    unsigned char unk0E;
    unsigned char unk0F;
};

struct Node {
    unsigned char unk00[0x0C];
    int unk0C;
    int unk10;
    unsigned char unk14[0x2C];
    int unk40;
    unsigned char unk44[0x14];
    unsigned char *unk58;
    unsigned char unk5C;
    unsigned char unk5D[3];
    void (*unk60)(void);
    unsigned char unk64[0x5B];
    unsigned char unkBF;
    unsigned char unkC0[0x28];
    int unkE8;
    unsigned char unkEC[4];
    unsigned char unkF0;
    unsigned char unkF1;
    unsigned char unkF2[2];
    unsigned char unkF4;
    unsigned char unkF5;
    unsigned char unkF6;
    unsigned char unkF7[9];
    unsigned char unk100;
    unsigned char unk101;
    unsigned char unk102[2];
    unsigned char unk104;
    unsigned char unk105;
    unsigned char unk106;
    unsigned char unk107;
    unsigned short unk108;
    unsigned char unk10A[2];
    int unk10C;
    int unk110;
    int unk114;
};

struct Node *sub_0803C820(unsigned char arg0, unsigned char arg1)
{
    struct Entry *entry = sub_08004A14(arg0, arg1);
    struct Node *node = sub_08000234();

    node->unk5C = entry->unk00;
    node->unk58 = gUnknown_05000008;
    node->unkBF = 0x80;
    sub_08002138(node, 3);
    sub_080020FC(node, 0);
    node->unkF0 = node->unkF1 = 0;
    node->unk100 = 0;
    node->unkF6 = 0x1E;
    node->unk60 = sub_0803C91C;
    node->unkF4 = 0;
    sub_08000DA4(node, entry->unk04, entry->unk06);
    node->unk40 = sub_0801419C(node->unk0C, node->unk10) + (entry->unk08 << 16);
    sub_080144F4(node);
    node->unk101 = entry->unk09;
    node->unk104 = entry->unk0D;
    node->unk105 = entry->unk0C;
    node->unkE8 = 0;
    node->unk114 = sub_08004A5C(entry->unk0A, entry->unk0B);
    node->unk106 = entry->unk0E;
    node->unk108 = entry->unk0F;
    node->unk110 = 0;
    node->unk10C = 0;
    return node;
}
