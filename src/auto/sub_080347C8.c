struct Node
{
    unsigned char unk00[0x0C];
    int pos_x;
    int pos_y;
    unsigned char unk14[0x44];
    unsigned int flags;
    unsigned char unk5C[0x0C];
    struct Node *child;
    unsigned char unk6C[0x75];
    unsigned char unkE1;
    unsigned char unkE2[0x0F];
    unsigned char unkF1;
    unsigned char unkF2[0x1A];
    unsigned int unk10C;
};

struct Pos
{
    int x;
    int y;
};

int sub_0802B6F0(struct Node *obj);
void sub_08001080(struct Node *obj, int flag, struct Pos *out);
extern void sub_08002138(void *, unsigned int);

void sub_080347C8(struct Node *node)
{
    struct Pos pos;

    if (node->unkE1 == 1)
        return;
    if (sub_0802B6F0(node->child)) {
        sub_08001080(node->child, 1, &pos);
        node->pos_x = pos.x;
        node->pos_y = pos.y;
    } else {
        node->pos_x = node->child->pos_x;
        node->pos_y = node->child->pos_y;
    }
    if (node->child->unkF1 == 0)
        return;
    sub_08002138(node, 1);
}
