struct Node
{
    unsigned char unk00[0x58];
    unsigned int flags;
    unsigned char unk5C[0x80];
    unsigned short unkDC;
    unsigned char unkDE[3];
    unsigned char unkE1;
};

extern void sub_08000494(struct Node *node);

void sub_08033700(struct Node *node)
{
    if (--node->unkDC == 0) {
        sub_08000494(node);
    }
    if (node->unkE1 == 1) {
        sub_08000494(node);
    }
}
