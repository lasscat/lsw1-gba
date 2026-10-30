extern void sub_08021678(void *r0);
extern void sub_08021748(void);
extern void sub_0801D47C(void *r0, void *r1);
extern int sub_0800EB7C(int r0);

int sub_08021574(void *r0, void *r1)
{
    unsigned char *p;
    unsigned int mask;

    sub_08021678(r0);
    p = (unsigned char *)r0 + 0xb1;
    mask = 0xd;
    mask = -mask;
    *p = (*p & (unsigned char)mask) | 4;
    *(void **)((unsigned char *)r0 + 0x60) = sub_08021748;
    sub_0801D47C(r0, r1);
    {
        int v = sub_0800EB7C((int)r1);
        v = (v + 1);
        v = v / 2;
        return 0x78 - v;
    }
}
