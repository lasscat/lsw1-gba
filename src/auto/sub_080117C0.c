extern unsigned char gUnknown_0300332C[];

struct S117C0 {
    unsigned int unk[22];
    unsigned int flags;
};

void sub_080117C0(void)
{
    unsigned int i = 0;
    unsigned char *base = gUnknown_0300332C;
    int mask = 2;
    int val = 0;
    struct S117C0 **slot = (struct S117C0 **)(base + 0x7c);
    struct S117C0 *p;

    do {
        p = *slot;
        if (p != 0 && (p->flags & mask) != 0)
            *slot = (struct S117C0 *)val;
        slot++;
        i++;
    } while (i <= 2);
}
