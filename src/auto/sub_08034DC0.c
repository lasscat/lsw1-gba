typedef struct Obj {
    unsigned char f0[16];
    unsigned int f10;
    unsigned char f14[84];
    struct Obj *f68;
    unsigned char f6C[73];
    unsigned char fB5;
    unsigned char fB6[6];
    unsigned short fBC;
    unsigned char fBE;
    unsigned char fBF;
    unsigned char fC0[34];
    unsigned char fE2;
} Obj;
 void sub_08034DC0(Obj *p)
{
    unsigned char *s;
    unsigned char *d;
    unsigned int t;
    unsigned int u;
    p->fE2 = 0x14;
    s = &p->f68->fB5;
    d = &p->fB5;
    t = *s & 0xC;
    u = *d & ~0xC;
    p->fB5 = u | t;     p->fBF = p->f68->fBF;
    p->f10 += 0x10000;
    p->fBC |= 0x20;
}
