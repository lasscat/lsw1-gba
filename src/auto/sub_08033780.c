struct Node
{
    unsigned char unk00[0x58];
    unsigned int flags;
};

struct Node2
{
    unsigned char unk00[0xe2];
    unsigned char unkE2;
};

void sub_08000494(struct Node *node);

void sub_08033780(struct Node *node)
{
    struct Node2 *unk = *(struct Node2 **)((unsigned char *)node + 0x68);
    if (unk->unkE2 != 0x4d)
    {
        sub_08000494(node);
    }
}
