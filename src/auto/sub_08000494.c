/* Placeholder names: the struct and the meaning of the flag bits are not known yet. */

struct Node
{
    unsigned char unk00[0x58];
    unsigned int flags;
};

/* Sets bit 1 and clears bit 0 of the node's flags. */
void sub_08000494(struct Node *node)
{
    node->flags |= 2;
    node->flags &= ~1;
}
