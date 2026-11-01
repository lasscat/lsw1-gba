typedef unsigned char u8;
typedef unsigned short u16;

struct Sub {
    u8 pad0[0x58];
    unsigned int flags;
};

struct Obj {
    u8 pad0[0xC];
    int x;
    int y;
    u8 pad1[0x58 - 0x14];
    unsigned int flags;
    u8 pad2[0x64 - 0x5C];
    struct Sub *link;
    u8 pad3[0xE0 - 0x68];
    u8 kind;
    u8 kind2;
    u8 pad4[0xF0 - 0xE2];
    u16 f0;
    u16 f2;
    u8 pad6[2];
    u16 f6;
    u8 pad7[0x115 - 0xF8];
    u8 b115;
    u8 pad8;
    u8 b117;
    u8 pad9;
    u8 b119;
};

struct Ent {
    struct Obj *target;
    u8 pad[120];
};

struct A { u8 pad[6]; u8 v; u8 pad2[5]; };
struct B { u8 pad[0x14]; u8 idx; u8 pad2[3]; };
struct C { u8 pad0[0x10]; void (*fn)(struct Obj *, struct Obj *, int); u8 pad[4]; };

extern struct Ent gUnknown_0300332C[];
extern struct A gUnknown_0804F614[];
extern struct B gUnknown_08056D60[];
extern struct C gUnknown_08056D30[];

extern unsigned int sub_08013254(unsigned int, unsigned int, unsigned int, unsigned int);
extern int sub_0801419C(int x, int y);
extern void sub_08038128(void *a, unsigned int b, int c);

void sub_08038594(struct Obj *a, int idx)
{
    int arg = 0;
    int *p;
    int flag;
    struct Obj *t;
    unsigned int m;
    int d;
    unsigned int r;

    if (a->link != 0 && (a->link->flags & 2)) {
        a->link = 0;
        sub_08038128(a, 0, 0);
        return;
    }
    if (a->kind2 == 0x22 || a->kind2 == 0x25 || a->kind2 == 0x26 || a->kind2 == 0x33)
        return;
    t = gUnknown_0300332C[idx].target;
    p = &arg;
    flag = 0;
    m = a->f2 & 7;
    if ((a->flags & 0x400) || m != 0) {
        if (a->f6 == 0) {
            d = sub_0801419C(a->x, a->y) - sub_0801419C(t->x, t->y);
            if (d < 0)
                d = -d;
            d >>= 16;
            if (d > 0 && m != 0 && a->kind == 0x49) {
                sub_08038128(a, 0, 0);
                goto tail; // FAKE: block-order goto, call path skips the flag test
            } else if (d == 0 || ((a->f0 & 0x40) && d <= 0x2F)) {
                r = sub_08013254(a->x, a->y, t->x, t->y) >> 16;
                if ((int)r < a->b115) {
                    flag = 1;
                    *p = gUnknown_0804F614[a->kind].v;
                    if ((int)r < a->b115 / 2)
                        *p = *p * 4;
                }
            }
            if (flag)
                goto done; // FAKE: block-order goto, skip the -b117 default
        }
    }
tail:
    if ((a->f2 & 0x20) == 0)
        arg = -a->b117;
done:
    gUnknown_08056D30[gUnknown_08056D60[a->b119].idx].fn(a, t, arg);
}
