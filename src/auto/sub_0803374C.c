struct Node
{
    unsigned char unk00[0x58];
    unsigned int flags;
};

extern void sub_08000494(struct Node *node);

void sub_0803374C(struct Node *node)
{
    if (node->flags & 0x40000) {
        sub_08000494(node);
    }
}
