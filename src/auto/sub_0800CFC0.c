struct S0800CFC0
{
    struct S0800CFC0 *next;
    unsigned char _04[84];
    unsigned int flags;
    unsigned char kind;
};

extern struct S0800CFC0 *gUnknown_030024EC;

void sub_0800CFC0(void)
{
    struct S0800CFC0 *p = gUnknown_030024EC;
    struct S0800CFC0 *next;
    while (p != 0)
    {
        next = p->next;
        if (p->kind == 12)
            p->flags |= 2;
        p = next;
    }
}
