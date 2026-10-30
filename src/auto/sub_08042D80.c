/* Placeholder names: the struct and the meaning of the fields are not known yet. */

struct Node
{
    struct Node *next;
    unsigned char unk04[8];
    int unk0c;
    int unk10;
    unsigned char unk14[0x2c];
    int unk40;
    unsigned char unk44[0x14];
    unsigned int flags;
    unsigned char unk5c;
    unsigned char unk5d[0x97];
    unsigned char unkf4;
    unsigned char unkf5;
    unsigned char unkf6;
    unsigned char unkf7;
};

extern struct Node *gUnknown_030024EC;

void sub_08033374(int a, int b);
void sub_080312B0(int a, int b, int c, int d, int e, int f, int g, void *h);

void sub_08042D80(void)
{
    struct Node *node = gUnknown_030024EC;

    if (!node) {
        return;
    }
    do {
        struct Node *next = node->next;

        if (node->unk5c == 0xB && node->unkf7 == 6) {
            sub_08033374((int)node, 0x34);
            sub_080312B0(node->unk0c, node->unk10, node->unk40, 0x320000, 0x140000, node->unkf4, node->unkf5, 0);
            node->flags = (node->flags & ~1) | 2;
        }
        node = next;
    } while (node);
}
