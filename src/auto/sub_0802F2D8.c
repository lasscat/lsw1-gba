extern int sub_0802F278(int x, void *p);

void sub_0802F2D8(void *a)
{
    void *r4 = a;
    unsigned char *p;
    int v;

    p = (unsigned char *)r4 + 0x108;
    if (*p == 0) {
        return;
    }

    v = sub_0802F278(*p, p);

    if (v == 0x13) {
        return;
    }

    *(unsigned char *)((char *)r4 + 0x107) = v;
}
