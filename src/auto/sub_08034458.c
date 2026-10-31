struct Node
{
    unsigned char unk00[0x0C];
    int pos_x;
    int pos_y;
    unsigned char unk14[0x44];
    unsigned int flags;
    unsigned char unk5C[0x0C];
    struct Node *child;
    unsigned char unk6C[0x47];
    unsigned char unkB3;
};

struct Pos
{
    int x;
    int y;
};

int sub_08001080(struct Node *obj, int flag, struct Pos *out);

void sub_08034458(struct Node *node)
{
    struct Pos pos;
    unsigned char *s = &node->child->unkB3;
    unsigned char *d = &node->unkB3;
    unsigned int a = *s;
    unsigned int b = *d;
    int m = 0x11;
    unsigned int x = a & 0x10;
    m = -m;
    *d = (b & m) | x;
    if (sub_08001080(node->child, 0, &pos)) {
        node->pos_x = pos.x;
        node->pos_y = pos.y;
    } else {
        int y = node->child->pos_y;
        int x = node->child->pos_x;
        node->pos_x = x;
        node->pos_y = y;
    }
}
