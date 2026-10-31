struct Node
{
    unsigned char unk00[0x58];
    unsigned int flags;
    unsigned char unk5C[0x80];
    unsigned short unkDC;
    unsigned char unkDE[3];
    unsigned char unkE1;
    unsigned char unkE2[0x2D];
    unsigned char unk10F;
};

struct Entry
{
    unsigned char unk00[4];
    void (*func)(struct Node *node);
    unsigned char unk08[0x2C];
};

extern struct Entry gUnknown_08054F3C[];

void sub_08000494(struct Node *node);

void sub_080335C0(struct Node *node)
{
    void (*func)(struct Node *node);

    if (node->unkE1 == 1) {
        sub_08000494(node);
    }
    func = gUnknown_08054F3C[node->unk10F].func;
    if (func != 0) {
        func(node);
    }
}
