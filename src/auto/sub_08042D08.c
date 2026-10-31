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
    unsigned char unk5d[0xb];
    struct Node *unk68;
    unsigned char unk6c[0x88];
    unsigned char unkf4;
    unsigned char unkf5;
    unsigned char unkf6;
    unsigned char unkf7;
};

void sub_08033374(int a, int b);
void sub_080312B0(int a, int b, int c, int d, int e, int f, int g, void *h);

void sub_08042D08(struct Node *a, struct Node *b)
{
    if (a->unk68 == b) {
        return;
    }
    if (b->unk5c != 1) {
        return;
    }
    sub_08033374((int)a, 0x34);
    sub_080312B0(a->unk0c, a->unk10, a->unk40, 0x320000, 0x140000, a->unkf4, a->unkf5, a->unk68);
    a->flags = (a->flags & ~1) | 2;
}
