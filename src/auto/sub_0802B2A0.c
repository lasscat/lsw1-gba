typedef struct Obj Obj;
struct Obj {
    Obj *next;
    unsigned char _04[8];
    unsigned int x;
    unsigned int y;
    unsigned char _14[0x44];
    unsigned int flags58;
    unsigned char _5C;
    unsigned char _5D[2];
    unsigned char unk5F;
    unsigned char _60[0xC];
    unsigned int unk6C;
    unsigned char _70[0x64];
    unsigned int unkD4;
    unsigned char _D8[8];
    unsigned char unkE0;
    unsigned char _E1;
    unsigned char unkE2;
    unsigned char unkE3;
    unsigned char _E4[4];
    unsigned int unkE8;
    unsigned char _EC[5];
    unsigned char unkF1;
};

extern Obj *gUnknown_0300340C;
extern Obj *gUnknown_030024EC;
extern int gUnknown_0300332C[];
extern unsigned char gUnknown_08057380[];
typedef struct { unsigned char _00[0x1E]; unsigned char unk1E; unsigned char _1F[0x11]; } Ent;
extern Ent gUnknown_0805171C[];

extern unsigned int sub_08013254(unsigned int, unsigned int, unsigned int, unsigned int);
extern int sub_0802B75C(void *);
extern int sub_0802BA14(void *);
extern int sub_0802B6B0(void *);
extern int sub_080015E0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, int e);
extern void sub_0802E2CC(void *);
extern void sub_08000F50(void *);
extern void sub_08002138(void *, unsigned int);
extern void sub_080020FC(void *, int);
extern void *sub_08033374(int, int);
extern int sub_0801BEB8(int);

static inline unsigned int dist(Obj *a, Obj *b)
{
    unsigned int y = a->y; // FAKE: y-before-x load order
    unsigned int x = a->x;
    return sub_08013254(x, y, b->x, b->y);
}

int sub_0802B2A0(Obj *p)
{
    Obj *o;
    Obj *g;
    unsigned int r;
    int zero = 0; // FAKE: steers r4/r5 allocation for the stack arg

    g = gUnknown_0300340C;
    if (gUnknown_0300340C->unkD4 & 4)
        return 0;
    if (gUnknown_08057380[g->unkE2] & 0x10)
        return 0;
    if (sub_08013254(g->x, g->y, p->x, p->y) > 0x4B0000)
        return 0;
    if (sub_0802B75C(p) != 0) {
        if (p->_5C == 0x18 && gUnknown_0805171C[p->unkE0].unk1E == 0) {
            if (gUnknown_0300340C->unk6C != p->unkE8)
                return 0;
        } else if (sub_0802BA14(p) != 0) {
            return 0;
        }
    }

    for (o = gUnknown_030024EC; o != 0; o = o->next) {
        if ((o->flags58 & 0x400) && sub_0802B6B0(o) && o->unkF1 == 0
            && (unsigned char)(o->unkE0 - 0x64) > 1) {
            if (dist(gUnknown_0300340C, p) > dist(gUnknown_0300340C, o))
                return 0;
        }
    }

    {
        unsigned int y = gUnknown_0300340C->y; // FAKE: y-before-x load order
        unsigned int x = gUnknown_0300340C->x;
        r = sub_080015E0(x, y, p->x, p->y, zero);
    }
    if ((gUnknown_0300340C->flags58 & 0x2000) == 0) {
        gUnknown_0300340C->unk5F = ((r + 0x10) & 0xFF) >> 5;
        gUnknown_0300340C->unkE3 |= 0x10;
    }
    sub_0802E2CC(gUnknown_0300340C);
    sub_08000F50(gUnknown_0300340C);
    sub_08002138(gUnknown_0300340C, 0);
    sub_080020FC(gUnknown_0300340C, 0x2F);
    gUnknown_0300340C->unkD4 |= 4;
    sub_08033374(p, 0x29);
    sub_08033374(gUnknown_0300340C, 0x27);
    sub_08033374(gUnknown_0300340C, 0x28);
    gUnknown_0300332C[0xA0 / 4] = sub_0801BEB8(0x22);
    return 1;
}
