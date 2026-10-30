struct S
{
    unsigned char unk00[0x68];
    struct S *child;
    unsigned char unk6C[0x49];
    unsigned char unkB5;
    unsigned char unkB6[0x09];
    unsigned char unkBF;
    unsigned char unkC0[0x4C];
    struct S *unk10C;
};

void sub_08034668(struct S *node)
{
    unsigned char *s = &node->child->unkB5;
    unsigned char *d = &node->unkB5;
    unsigned int a = *s & 0x0C;
    unsigned int b = *d & -13;
    *d = b | a;
    node->unkBF = node->child->unkBF - 1;
    node->child->unk10C = node;}
