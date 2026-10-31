typedef struct Obj {
    struct Obj *next;
    unsigned char pad0[8];
    unsigned int f12;
    unsigned int f16;
    unsigned char pad1[0x58 - 0x14];
    int f58;
    unsigned char f5C;
    unsigned char padA[2];
    unsigned char f5F;
    unsigned char pad2[0xD8 - 0x60];
    short fD8;
    unsigned char padB[6];
    unsigned char fE0;
} Obj;

extern Obj *gUnknown_030024EC;
int sub_080015E0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, int e);
extern unsigned int sub_08013254(unsigned int, unsigned int, unsigned int, unsigned int);
static inline int iabs(int x)
{
    if (x < 0)
        x = -x;
    return x;
}

Obj *sub_0802AD08(Obj *p, unsigned int a, unsigned int b)
{
    Obj *cur;
    Obj *best;
    unsigned int bestDist;
    int base;
    if (p->f58 < 0)
        base = p->f5F;
    else
        base = p->f5F << 5;
    best = 0;
    bestDist = b;
    cur = gUnknown_030024EC;
    while (cur != 0) {
        unsigned int t = cur->f5C;
        if (t == 12 || t == 19 || t == 7 || t == 28) {
            if (cur->fD8 != 0 && cur->fE0 > 43) {
                int ang = sub_080015E0(p->f12, p->f16, cur->f12, cur->f16, 1);
                if (ang != 256) {
                    int d = iabs(ang - base);
                    if ((unsigned int)d > 128)
                        d = 255 - d;
                    if ((unsigned int)d < a) {
                        unsigned int dist = sub_08013254(cur->f12, cur->f16, p->f12, p->f16);
                        if (dist < b && dist < bestDist) {
                            best = cur;
                            bestDist = dist;
                        }
                    }
                }
            }
        }
        cur = cur->next;
    }
    return best;
}
