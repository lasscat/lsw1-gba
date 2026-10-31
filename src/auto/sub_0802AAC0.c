typedef struct Sub2AAC0Node {
    struct Sub2AAC0Node *next;
    unsigned char fill_04[88];
    unsigned char kind;
    unsigned char fill_5D[131];
    unsigned char match;
} Sub2AAC0Node;

extern Sub2AAC0Node *gUnknown_030024EC;

int sub_0802AAC0(int v)
{
    int n = 0;
    Sub2AAC0Node *p = gUnknown_030024EC;
    while (p != 0) {
        if (p->match == v) {
            if (p->kind == 12 || p->kind == 19 || p->kind == 7 || p->kind == 28)
                n++;
        }
        p = p->next;
    }
    return n;
}
