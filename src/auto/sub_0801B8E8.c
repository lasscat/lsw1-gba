extern unsigned int gUnknown_030049F0[];

void sub_0801B8E8(int a, unsigned int b)
{
    unsigned int *p = gUnknown_030049F0;
    unsigned int *q = &p[0xB8];
    unsigned int *r;
    unsigned int *t;
    q[0] = a;
    q[1] = b;
    r = &p[0xBA];
    r[0] = a;
    r[1] = b;
    r = &p[0xBC];
    r[0] = a;
    r[1] = b;
    t = &p[0xBE];
    t[0] = a;
    t[1] = b;
    q[0] = a >> 1;
}
