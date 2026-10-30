struct Node
{
    unsigned char unk00[0x58];
    unsigned int flags;
};

void sub_08000494(struct Node *node);

void sub_08033414(struct Node *node)
{
    sub_08000494(node);
}
