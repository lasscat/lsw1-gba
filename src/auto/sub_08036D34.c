extern unsigned char gUnknown_08056C3C[];
extern unsigned char gUnknown_0805671C[];

extern int sub_080369BC(unsigned char *p);
extern void sub_08036A08(void *a, int b);

struct S36D34 {
    unsigned char _00[0x64];
    int v64;
    unsigned char _68[0x70];
    short sD8;
    short sDA;
    unsigned char _DC[0x3D];
    unsigned char b119;
};

void sub_08036D34(struct S36D34 *p, int v)
{
    unsigned char idx;

    p->v64 = v;
    idx = p->b119;
    if (p->sD8 < (p->sDA >> 1))
        idx = gUnknown_08056C3C[idx];
    sub_08036A08(p, sub_080369BC(&gUnknown_0805671C[idx * 12]));
}
