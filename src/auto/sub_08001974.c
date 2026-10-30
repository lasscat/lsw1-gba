struct A
{
    unsigned char unk0[151];
    unsigned char unk97;
};
struct P
{
    unsigned char unk0[10];
    unsigned char count;
    unsigned char unkB;
    unsigned short table[256];
};
int sub_08001974(struct A *a, struct P *p, unsigned int idx, int *out)
{
    unsigned int t;
    signed char *q;
    if (idx >= p->count)
        return 0;
    t = p->table[a->unk97] + 12;
    q = (signed char *)p + t + (idx * 2 + 10);
    out[0] = q[0];
    out[1] = q[1];
    return 1;
}
