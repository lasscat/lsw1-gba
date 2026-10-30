struct Node
{
    unsigned char unk00[0x58];
    unsigned int flags;
    unsigned char unk5C[0x60];
    unsigned short unkBC;
};

extern struct Node *gUnknown_030024F8[];
extern unsigned int gUnknown_03002730;

void sub_08002FC0(struct Node *node);

void sub_08002D24(void)
{
    int i;

    for (i = 0; i < gUnknown_03002730; i++) {
        struct Node *node = gUnknown_030024F8[i];

        if (node->flags & 0x100000) {
            node->unkBC |= 0x80;
            sub_08002FC0(node);
            node->unkBC &= 0xFF7F;
        }
    }
}
