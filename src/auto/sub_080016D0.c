struct Node {
    struct Node *next;
    unsigned char pad[88];
    unsigned char f5c;
    unsigned char pad2[131];
    unsigned char fe0;
};

extern struct Node *gUnknown_030024EC;

unsigned int sub_080016D0(unsigned int a, unsigned int b, struct Node **out, unsigned int max)
{
    unsigned char count = 0;
    struct Node *cur = gUnknown_030024EC;
    while (cur != 0 && count < max) {
        struct Node *next = cur->next;
        if (cur->f5c == a && cur->fe0 == b) {
            out[count] = cur;
            count++;
        }
        cur = next;
    }
    return count;
}
