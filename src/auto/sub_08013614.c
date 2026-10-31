struct Block
{
    struct Block *prev;
    struct Block *next;
    struct Block *fnext;
    struct Block *fprev;
};

struct Slot
{
    struct Block *head;
    char pad[12];
};

extern struct Slot gUnknown_0300367C[];
extern unsigned int gUnknown_03003688;

int sub_080139C4(void *arg0, int arg1);
void sub_080139FC(struct Block *a, struct Block *b);
void sub_08013A28(struct Block *a, struct Block *b);
void sub_08013ADC(struct Block *a, int b);

void *sub_08013614(int arg0)
{
    unsigned int size = (arg0 + 15) & -16;
    struct Block *p;
    struct Block *q;
    unsigned int i;
    unsigned int avail;
    struct Slot *tbl;

    i = 0;
    if (i < gUnknown_03003688) {
        tbl = gUnknown_0300367C;
top:
        p = tbl[i].head;
test:
        if (p == 0)
            goto next_i; // FAKE: hand-rolled loop; structured while miscompiles (loop induction/stepping/rotation)
        avail = sub_080139C4(p, i);
        if (avail >= size)
            goto found; // FAKE: hand-rolled loop; structured while miscompiles (loop induction/stepping/rotation)
        p = p->fnext;
        goto test; // FAKE: hand-rolled loop; structured while miscompiles (loop induction/stepping/rotation)
found:
        if (avail > size) {
            size += 16;
            q = (struct Block *)((char *)p + size);
            sub_080139FC(p, q);
            sub_08013A28(p, q);
        }
        sub_08013ADC(p, i);
        p->fnext = (struct Block *)i;
        p->fprev = (struct Block *)-1;
        return (void *)((char *)p + 16);
next_i:
        i++;
        if (i < gUnknown_03003688)
            goto top; // FAKE: hand-rolled loop; structured while miscompiles (loop induction/stepping/rotation)
    }
    return 0;
}
