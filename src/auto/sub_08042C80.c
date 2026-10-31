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
    unsigned char unk5c[0x98];
    unsigned char unkf4;
    unsigned char unkf5;
};

struct Other
{
    unsigned char unk00[0x5c];
    unsigned char unk5c;
    unsigned char unk5d[0x85];
    unsigned char unke2;
};

void sub_08033374(int a, int b);
void sub_080312B0(int a, int b, int c, int d, int e, int f, int g, void *h);

void sub_08042C80(struct Node *a, struct Other *b)
{
    if (b->unk5c == 0xc || b->unk5c == 0x13 || b->unk5c == 7 || b->unk5c == 0x1c || b->unk5c == 1) {
        if (b->unke2 != 0xf) {
            sub_08033374((int)a, 0x34);
            sub_080312B0(a->unk0c, a->unk10, a->unk40, 0x320000, 0x140000, a->unkf4, a->unkf5, a);
            a->flags = (a->flags & ~1) | 2;
        }
    }
}
