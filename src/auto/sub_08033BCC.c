struct Node
{
    unsigned char unk00[0x0c];
    int pos_x;
    int pos_y;
    unsigned char unk14[0x10];
    int unk24;
    int unk28;
    unsigned char unk2C[0x14];
    int unk40;
    int unk44;
    unsigned char unk48[0x10];
    unsigned int flags;
    unsigned char unk5C;
    unsigned char unk5D[2];
    unsigned char unk5F;
    unsigned char unk60[8];
    struct Node *child;
    unsigned char unk6C[0x49];
    unsigned char unkB5;
    unsigned char unkB6[9];
    unsigned char unkBF;
    unsigned char unkC0[0x1c];
    unsigned short unkDC;
    unsigned char unkDE[2];
    unsigned char unkE0;
    unsigned char unkE1;
};

struct Pos
{
    int x;
    int y;
};

void sub_08000494(struct Node *node);
int sub_08001080(struct Node *obj, int flag, struct Pos *out);

void sub_08033BCC(struct Node *node)
{
    struct Pos pos;
    int m = 13;


    if (node->child->unkE0 == 0x45 || node->child->unkE0 == 0x47 || node->child->unkE0 == 0x46) {
        sub_08001080(node->child, 1, &pos);
        node->pos_x = pos.x;
        node->pos_y = pos.y;
        if (node->child->unkE1 != 0x33) {
            sub_08000494(node);
        }
    } else {
        sub_08001080(node->child, 0, (struct Pos *)&node->pos_x);
        node->unk40 = node->child->unk40 + (0xa0 << 12) + node->child->unk44;
        node->pos_x += node->child->unk24;
        node->pos_y += node->child->unk28;
        if (node->flags & (0x80 << 18)) {
            if (node->flags & (0x80 << 11)) {
                sub_08000494(node);
            }
        }
        if (node->child->unk5C == 1) {
            unsigned char *s = (unsigned char *)node->child + 0xb5;
            unsigned char *d = (unsigned char *)node + 0xb5;
            unsigned int u = *s & 0xc;
            *d = (*d & -m) | u;
            if ((unsigned char)(node->child->unk5F - 1) > 4) {
                node->unkBF = 0x80;
            } else {
                node->unkBF = 5;
            }
        }
    }
    if (node->unkDC == 0) {
        node->flags |= 1;
    } else {
        node->unkDC--;
    }
}
