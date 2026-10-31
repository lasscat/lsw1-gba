extern void sub_0801C19C(unsigned int arg);

void sub_0802E098(unsigned char *arg0, int arg1)
{
    unsigned int *p;
    unsigned int v;

    if (arg0[0x5c] != 1)
        return;
    p = *(unsigned int **)(arg0 + 0xe8);
    *(unsigned int *)(arg0 + 0xe8) = 0;
    while (p != 0) {
        *(unsigned int *)((unsigned char *)p + 0x58) |= 2;
        p = *(unsigned int **)((unsigned char *)p + 0xec);
    }
    if (arg1 == 0)
        return;
    v = *(unsigned int *)(arg0 + 0x11c);
    if (v != 0)
        sub_0801C19C(v);
}
