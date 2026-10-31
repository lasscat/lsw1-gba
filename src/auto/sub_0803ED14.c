extern void *sub_08004A14(unsigned char a, unsigned char b);
extern void sub_08004458(unsigned char a, unsigned char b);
extern void sub_08000D00(void *arg0, int arg1);
extern unsigned char gUnknown_0807025F[];

struct Entry
{
    unsigned char unk00[0x0E];
    unsigned char unk0E;
    unsigned char unk0F;
};

struct Node
{
    unsigned char unk00[0x5D];
    unsigned char unk5D;
    unsigned char unk5E;
    unsigned char unk5F[0x82];
    unsigned char unkE1;
    unsigned char unkE2[0x28];
    unsigned char unk10A;
};

void sub_0803ED14(struct Node *node)
{
    struct Entry *entry;

    entry = sub_08004A14(node->unk5D, node->unk5E);
    sub_08004458(entry->unk0E, entry->unk0F);
    sub_08000D00(node, gUnknown_0807025F[node->unk10A]);
    node->unkE1 = 0x0F;
}
