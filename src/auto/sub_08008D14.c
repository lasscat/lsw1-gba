struct P {
    int x;
    int y;
};

struct Obj {
    unsigned char pad0[0xC];
    int unkC;
    int unk10;
    unsigned char pad14[0x58 - 0x14];
    unsigned int unk58;
    unsigned char unk5C;
    unsigned char pad5D[2];
    unsigned char unk5F;
    unsigned char pad60[0x68 - 0x60];
    struct Obj *unk68;
    unsigned char pad6C[0xE0 - 0x6C];
    unsigned char unkE0;
    unsigned char padE1;
    unsigned char unkE2;
    unsigned char padE3[0xF0 - 0xE3];
    unsigned short unkF0;
    unsigned char padF2[2];
    unsigned char unkF4;
    unsigned char unkF5;
    unsigned char padF6;
    unsigned char unkF7;
    unsigned char padF8;
    unsigned char unkF9;
    unsigned char padFA;
    unsigned char unkFB;
};

extern int gUnknown_03002F2C;
extern unsigned char gUnknown_03006B1C[];

extern void sub_080020FC(struct Obj *obj, int val);
extern int sub_08008948(void *arg0, void *arg1);
extern int sub_080130D4(struct P p);
extern void sub_080310A0(struct Obj *obj, int a, int b);
extern void *sub_08033374(struct Obj *a, int b);
extern void sub_08037BCC(void *arg0, int arg1, int arg2);
extern void sub_080393C4(struct Obj *a, unsigned char b);
extern void sub_08043664(struct Obj *a, struct Obj *b);
extern void sub_080436FC(struct Obj *a, struct Obj *b);

static inline int Abs(int x)
{
    if (x < 0) x = -x;
    return x;
}

static inline int AngDiff(int ang, struct Obj *o)
{
    int d = ang - 0x40;
    if (d > 0x100) d = ang - 0x140;
    if (d < 0) d += 0x100;
    d = Abs(d - o->unk5F);
    if (d > 0x80) d = 0xFF - d;
    return d;
}

void sub_08008D14(struct Obj *a, struct Obj *b)
{
    unsigned char f7;
    int t;
    if (a->unk58 & 2) return;
    if (gUnknown_03002F2C != 0) return;
    if (sub_08008948(a, b) != 0) return;
    if (a->unk68 == b) return;
    if (a->unkE2 == 6) return;

    if (b->unk5C == 8 || b->unk5C == 0xC) {
        if (b->unkF0 & 0x400) return;
    
        f7 = a->unkF7;
        if (b->unkE0 == 0x63 || b->unkE0 == 0x65 || b->unkE0 == 0x61 || b->unkE0 == 0x62) {
            if (f7 <= 1 || f7 == 0xC) {
                struct P p;
                int ang, d, e, u;
                p.x = b->unkC - a->unkC;
                p.y = b->unk10 - a->unk10;
                ang = sub_080130D4(p);
                d = AngDiff(ang, b);
                u = a->unkF9 << 3;
                e = u + 0x80;
                if (e > 0xFF) e = u - 0x80;
                e = Abs(e - (b->unk5F << 5));
                if (d <= 0x27 || e <= 0x36) {
                    sub_080310A0(a, 1, 1);
                    return;
                }
            }
        }
    
        if (a->unkFB & 0x10) {
            unsigned char *base = gUnknown_03006B1C;
            unsigned short *cnt = (unsigned short *)(base + 0x3B2);
            if (*cnt <= 0x3E6) *cnt = *cnt + 1;
            sub_080393C4(a, 0x3D);
        }
    
        if (a->unkF5 == 6) b->unk5F = (a->unk5F + 4) << 5;
        if (a->unkF7 == 5) a->unk58 &= ~0x200;
        if (!(a->unkFB & 1)) {
            unsigned char v = a->unkF4;
            if ((b->unkF0 & 0x4000) && a->unkF7 == 4) v >>= 2;
            sub_08037BCC(b, v, a->unkF5);
        }
        t = a->unkFB & 4;
        if (t == 0) {
            sub_080020FC(a, 6);
            a->unk58 &= ~4;
        }
    } else if ((b->unk5C == 0x22 && a->unkF7 != 9 && a->unkF7 != 5 && a->unkF7 != 4 && a->unkF7 != 7)
               || b->unk5C == 0x21) {
        if (b->unk5C == 0x21) sub_080436FC(b, a);
        else sub_08043664(b, a);
        t = a->unkFB & 4;
        if (t == 0) {
            sub_080020FC(a, 6);
            a->unk58 &= ~4;
        }
    } else {
        struct Obj *r;
        if (b->unk5C != 0x14) return;
        if (b->unkE0 != 0xE) return;
        if (a->unkF7 == 4) return;
        if (a->unkF7 != 5) {
            if (gUnknown_03006B1C[0x293] == 0x10) sub_08033374(a, 0x4F);
            else sub_08033374(a, 0x4E);
        } else {
            if (a->unkE2 == 0x49) return;
            if (gUnknown_03006B1C[0x293] == 0x10) r = sub_08033374(a, 0x4F);
            else r = sub_08033374(a, 0x4E);
            r->unk68 = 0;
            sub_080020FC(a, 0x49);
        }
    }
}
