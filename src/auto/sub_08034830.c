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
    unsigned char unkE2[0x2A];
    unsigned int unk10C;
};

struct Pos
{
    int x;
    int y;
};

void sub_08000494(struct Node *node);
int sub_0802B6F0(struct Node *obj);
void sub_08001080(struct Node *obj, int flag, struct Pos *out);

void sub_08034830(struct Node *node)
{
    struct Pos pos;

    if (node->unkE1 == 1 || node->child->flags & 2) {
        sub_08000494(node);
        node->child->unk10C = 0;
    } else if (node->child->unkE1 == 1) {
        sub_08000494(node);
        node->child->unk10C = 0;
    } else if (sub_0802B6F0(node->child)) {
        sub_08001080(node->child, 1, &pos);
        node->pos_x = pos.x;
        node->pos_y = pos.y;
    } else {
        node->pos_x = node->child->pos_x;
        node->pos_y = node->child->pos_y;
    }
}
