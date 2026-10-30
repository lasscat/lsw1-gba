struct Node
{
    unsigned char unk00[0x58];
    unsigned int flags;
};

void sub_08002174(struct Node *node, unsigned int bits)
{
    node->flags |= bits;
}
