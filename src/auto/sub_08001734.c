struct Sub {
    unsigned char pad[92];
    unsigned char flag;
};

struct Node {
    struct Node *next;
    unsigned char pad1[88];
    unsigned char f5c;
    unsigned char pad2[11];
    struct Sub *sub;
    unsigned char pad3[116];
    unsigned char fe0;
};

extern struct Node *gUnknown_030024EC;

struct Node *sub_08001734(void)
{
    struct Node *r = gUnknown_030024EC;
    while (r != 0) {
        struct Node *next = r->next;
        if (r->f5c == 0x14 && r->fe0 == 0x16 && r->sub->flag == 1)
            return r;
        r = next;
    }
    return 0;
}
