struct Node
{
    unsigned char unk00[0x58];
    unsigned int flags;
};

int sub_080021BC(struct Node *node, unsigned int mask)
{
    if ((node->flags & mask) == mask) {
        return 1;
    }
    return 0;
}
