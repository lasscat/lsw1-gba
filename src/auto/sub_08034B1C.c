struct Node
{
    unsigned char unk00[0x0C];
    int pos_x;
    int pos_y;
    unsigned char unk14[0x44];
    unsigned int flags;
    unsigned char unk5C[0x0C];
    struct Node *child;
};

struct Pos
{
    int x;
    int y;
};

int sub_08001080(struct Node *obj, int flag, struct Pos *out);
extern void sub_08002138(void *, unsigned int);
extern unsigned int gUnknown_0300340C;

void sub_08034B1C(struct Node *node)
{
    struct Pos pos;
    unsigned int *r2;

    if (sub_08001080(node->child, 1, &pos)) {
        node->flags |= 1;
        node->pos_x = pos.x;
        node->pos_y = pos.y;
    }
    r2 = *(unsigned int **)&gUnknown_0300340C;
    if ((r2[0xD4 / 4] & 4) == 0)
        sub_08002138(node, 1);
}
