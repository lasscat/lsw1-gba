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

void sub_08035B54(struct Node *node)
{
    struct Node2 *unk = *(struct Node2 **)((unsigned char *)node + 0x68);
    if (unk->unkE2 == 2 || unk->unkE2 == 0x19 || unk->unkE2 == 9 || unk->unkE2 == 0x1f || unk->unkE2 == 0x4c || unk->unkE2 == 0x50 || unk->unkE2 == 0 || unk->unkE2 == 8 || unk->unkE2 == 0x46)
    {
        sub_08000494(node);
    }
}
