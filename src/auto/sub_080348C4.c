struct Node
{
    unsigned char unk00[0x0C];
    int pos_x;
    int pos_y;
    int unk14;
    int unk18;
    unsigned char unk1C[0x3C];
    unsigned int flags;
    unsigned char unk5C[0x0C];
    struct Node *child;
    unsigned char unk6C[0x68];
    unsigned int unkD4;
    unsigned char unkD8[0x04];
    unsigned short unkDC;
    unsigned char unkDE[0x36];
    unsigned char unk114;
};

struct Pos
{
    int x;
    int y;
};

void sub_08001080(struct Node *obj, int flag, struct Pos *out);
void sub_08035190(struct Node *node);

void sub_080348C4(struct Node *node)
{
    struct Pos pos;

    sub_08001080(node->child, 1, &pos);
    node->pos_x = pos.x;
    node->unk14 = pos.x;
    node->pos_y = pos.y;
    node->unk18 = pos.y;
    node->unkDC = 50;
    sub_08035190(node);
    node->flags |= 0x4015;
    node->unkD4 |= 0x80;
    node->unk114 = 50;
}
