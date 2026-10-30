struct Node
{
    unsigned char unk00[0x58];
    unsigned int flags;
};

void sub_080020D4(struct Node *node)
{
    node->flags &= -0x11;
}
