void sub_08000BF4(void *arg0, unsigned int arg1);
void sub_08009F6C(int a, int b, int c);
void sub_08009F98(int a, int b, int c);
extern int gUnknown_03006B14;

void sub_080007C8(void *arg0, int arg1, signed char arg2)
{
    unsigned char *p = (unsigned char *)arg0;
    unsigned char **pp = (unsigned char **)(p + 0xCC);
    int off = arg2 * 16;
    unsigned char *q;
    unsigned int v;
    unsigned int b;

    q = *pp;
    q += off;
    b = q[0xC];
    p[0x95] = (unsigned char)b;
    sub_08000BF4(p, (unsigned int)q);
    v = *(unsigned int *)(q + 8);
    if (v != 0) {
        if ((gUnknown_03006B14 & 0x10) != 0)
            sub_08009F6C((int)v, (p[0xB5] >> 4) << 4, 0x10);
        else
            sub_08009F98((int)v, (p[0xB5] >> 4) << 4, 0x10);
    }
}
