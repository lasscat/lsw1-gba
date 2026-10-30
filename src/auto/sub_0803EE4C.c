/* Placeholder names: the structs and the meaning of the flag bits are not known yet. */

extern void *sub_08004A14(unsigned char a, unsigned char b);
extern void sub_08004458(unsigned char a, unsigned char b);
extern void sub_08000D00(void *arg0, int arg1);

struct Entry
{
    unsigned char unk00[0x10];
    unsigned char unk10;
    unsigned char unk11;
};

struct Node
{
    unsigned char unk00[0x58];
    unsigned int flags;
    unsigned char unk5c;
    unsigned char unk5d;
    unsigned char unk5e;
    unsigned char unk5f[0x35];
    unsigned char unk94;
    unsigned char unk95;
};

void sub_0803EE4C(struct Node *node)
{
    struct Entry *entry;
    unsigned char *p;

    entry = sub_08004A14(node->unk5d, node->unk5e);
    sub_08004458(entry->unk10, entry->unk11);
    sub_08000D00(node, 0);
    node->flags |= 0x10;
    p = (unsigned char *)node + 0x95;
    *p = 0x14;
    p[-1] = 0x14;
}
