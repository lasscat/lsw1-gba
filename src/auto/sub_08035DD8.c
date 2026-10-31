struct Node
{
    unsigned char unk00[0x0C];
    int pos_x;
    int pos_y;
    unsigned char unk14[0x44];
    unsigned int flags;
    unsigned char unk5C[0x0C];
    void *child;
};

struct Child
{
    unsigned char unk00[0xDC];
    unsigned short unkDC;
};

void sub_08000494(struct Node *node);
void sub_08000D00(void *arg0, int arg1);
extern unsigned char gUnknown_0300332C[];
extern unsigned char gUnknown_08056174[];

void sub_08035DD8(struct Node *node)
{
    node->pos_x = 0xB00000;
    node->pos_y = 0x840000;
    if (((struct Child *)node->child)->unkDC == 0) {
        sub_08000494(node);
    } else {
        int t1 = gUnknown_0300332C[0xD3];
        int num = ((((signed char)t1 + 1) << 16) * 5);
        int t2 = gUnknown_0300332C[0xD4];
        int idx = ((num / (signed char)t2) >> 16);
        idx += 4;
        if (idx < 0)
            idx = 0;
        if (idx > 9)
            idx = 9;
        sub_08000D00(node, gUnknown_08056174[idx]);
    }
}
