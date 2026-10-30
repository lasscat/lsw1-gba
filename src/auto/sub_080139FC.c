struct ListNode {
    struct ListNode *prev;
    struct ListNode *next;
};

void sub_080139FC(struct ListNode *a, struct ListNode *b)
{
    struct ListNode *c;
    b->next = a;
    c = a->prev;
    b->prev = c;
    a->prev = b;
    if (c != 0) {
        c->next = b;
    }
}
