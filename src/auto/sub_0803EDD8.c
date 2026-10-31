extern void *sub_08004A14(unsigned char arg0, unsigned char arg1);
extern void sub_08000D00(void *arg0, int arg1);
extern unsigned char gUnknown_08070258[];

struct Node
{
    unsigned char unk00[0x58];
    unsigned int flags;
    unsigned char unk5C;
    unsigned char unk5D;
    unsigned char unk5E;
    unsigned char unk5F[0x82];
    unsigned char unkE1;
    unsigned char unkE2[0x1B];
    unsigned char unkFD;
    unsigned char unkFE;
    unsigned char unkFF;
    unsigned char unk100[0xA];
    unsigned char unk10A;
};

void sub_0803EDD8(struct Node *node)
{
    sub_08004A14(node->unk5D, node->unk5E);
    sub_08000D00(node, gUnknown_08070258[node->unk10A]);
    node->unkE1 = 0;
    node->flags &= ~0x10;
    node->unkFF = 1;
    node->flags |= 4;
    node->unkFD = 1;
}
