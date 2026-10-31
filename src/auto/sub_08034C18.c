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

extern unsigned int gUnknown_0300340C;
int sub_08001080(struct Node *obj, int flag, struct Pos *out);
extern void sub_08002138(void *, unsigned int);

void sub_08034C18(struct Node *node)
{
    struct Pos pos;

    if (sub_08001080(node->child, 0, &pos)) {
        node->flags |= 1;
        node->pos_x = pos.x;
        node->pos_y = pos.y;
    }
    if ((*(unsigned int *)(*(unsigned int *)&gUnknown_0300340C + 0xd4) & 4) == 0)
        sub_08002138(node, 1);
}
