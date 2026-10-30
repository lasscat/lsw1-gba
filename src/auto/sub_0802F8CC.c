struct N {
    unsigned char unk_00[190];
    unsigned char flag;
    unsigned char unk_BF[45];
    struct N *next;
};

int sub_0802F8CC(struct N *p, struct N **out)
{
    struct N *node = p;
    int count = 0;
    while (node != 0 && node->flag != 0) {
        count++;
        node = node->next;
    }
    *out = node;
    return count;
}
