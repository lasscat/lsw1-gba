struct Node
{
    unsigned char unk00[0x58];
    unsigned int flags;
    unsigned char unk5c[0x8e];
    unsigned char unk_ea;
    unsigned char unk_eb[9];
    struct Node *unk_f4;
};

typedef struct
{
    unsigned char pad_000[0xd0];
    unsigned int field_d0;
    unsigned char pad_d4[0x1e];
    unsigned short field_f2;
} Entity;

void sub_08000494(struct Node *node);

void sub_08040868(Entity *arg0)
{
    struct Node *node;

    node = (struct Node *)arg0->field_d0;
    if (node == 0)
        return;
    if (node->unk_ea == 0)
        return;
    if ((arg0->field_f2 & 7) == 0)
        return;
    node->flags |= 2;
    sub_08000494(((struct Node *)arg0->field_d0)->unk_f4);
}
