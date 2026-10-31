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
    unsigned char unkF2[0x1E];
    unsigned int unk110;
};

struct Pos
{
    int x;
    int y;
};

void sub_08000494(struct Node *node);
int sub_0802B6F0(struct Node *obj);
int sub_08001080(struct Node *obj, int flag, struct Pos *out);
int sub_0802BAD4(struct Node *obj);
extern void sub_08002138(void *, unsigned int);
extern unsigned int gUnknown_0300340C;

void sub_080346BC(struct Node *node)
{
    struct Pos pos;

    if (node->child->flags & 2) {
        sub_08000494(node);
        node->child->unk110 = 0;
        return;
    }
    if (node->flags & 2) {
        node->child->unk110 = 0;
        return;
    }
    if (node->unkE1 == 1) {
        sub_08000494(node);
        node->child->unk110 = 0;
        return;
    }
    if (sub_0802B6F0(node->child)) {
        sub_08001080(node->child, 1, &pos);
        node->pos_x = pos.x;
        node->pos_y = pos.y;
    } else {
        node->pos_x = node->child->pos_x;
        node->pos_y = node->child->pos_y;
    }
    if (node->child->unk5C[0] == 0x18 && (unsigned char)sub_0802BAD4(node->child) != 3) {
        if (node->child->unkE2[0] != 5 && (*(unsigned int *)(*(unsigned int *)&gUnknown_0300340C + 0xd4) & 4) != 0)
            return;
        sub_08002138(node, 1);
    } else {
        if (node->child->unkF1 == 0 && (*(unsigned int *)(*(unsigned int *)&gUnknown_0300340C + 0xd4) & 4) != 0)
            return;
        sub_08002138(node, 1);
        node->child->unk110 = 0;
    }
}
