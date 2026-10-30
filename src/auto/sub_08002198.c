/* Placeholder names: the struct and the meaning of the flag bits are not known yet. */

struct Node
{
    unsigned char unk00[0x58];
    unsigned int flags;
};

void sub_08002198(struct Node *node, unsigned int mask)
{
    node->flags &= ~mask;
}
