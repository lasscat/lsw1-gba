struct Node
{
    char unk0[8];
    struct Node *next;
    struct Node *prev;
};

void sub_08013A28(struct Node *a, struct Node *b)
{
    b->prev = a;
    b->next = a->next;
    a->next = b;
    if (b->next != 0)
    {
        b->next->prev = b;
    }
}
