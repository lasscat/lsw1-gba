struct Node_0802D368 {
    struct Node_0802D368 *next;
    unsigned char unk4[208];
    unsigned int unkD4;
};

extern struct Node_0802D368 *gUnknown_030024EC;

void sub_0802D368(void)
{
    struct Node_0802D368 *p;

    p = gUnknown_030024EC;
    while (p != 0) {
        p->unkD4 &= 0xDFFFFFFF;
        p = p->next;
    }
}
