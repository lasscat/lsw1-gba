struct QT { unsigned char a[10]; unsigned char count; unsigned char b; unsigned short t[1]; };
int sub_08001020(unsigned char *arg0, unsigned int arg1, int *arg2)
{
    unsigned char *p = *(unsigned char **)(arg0 + 0x98);
    struct QT *q = (struct QT *)*(unsigned char **)(p + 4);
    if (arg1 >= q->count)
        return 0;
    {
        unsigned int idx = arg0[0x97];
        unsigned short off = q->t[idx];
        signed char *s = (signed char *)((unsigned char *)q + 12 + off + 10 + arg1 * 2);
        arg2[0] = s[0];
        arg2[1] = s[1];
    }
    return 1;
}
