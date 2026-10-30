struct Node
{
    unsigned char unk00[0x58];
    unsigned int flags;
    unsigned char unk5C[0x34];
    void (*callback)(void *, void *);
    unsigned char unk94[0x5C];
    unsigned short unkF0;
};

void sub_080093B8(void *arg0, void *arg1);

void sub_08035190(struct Node *node)
{
    node->flags &= ~0x11;
    node->unkF0 |= 0x1000;
    node->flags |= 4;
    node->callback = sub_080093B8;
}
