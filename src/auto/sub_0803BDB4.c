struct Obj3BDB4 {
    char pad0[0xC];
    int unkC;
    int unk10;
    char pad14[0x2C];
    int unk40;
    char pad44[0x18];
    unsigned char unk5C;
    char pad5D[2];
    unsigned char unk5F;
    void (*unk60)(void);
    char pad64[0x14];
    unsigned char unk78;
    char pad79[0x17];
    void (*unk90)(void);
    char pad94[0x1D];
    unsigned char unkB1;
    char padB2[0x2E];
    unsigned char unkE0;
    char padE1;
    unsigned char unkE2;
    char padE3[0xD];
    unsigned short unkF0;
    unsigned short unkF2;
    char padF4[0xF];
    unsigned char unk103;
    char pad104[0x15];
    unsigned char unk119;
};

struct Tab4FB00 {
    char pad0[0x2C];
    unsigned short unk2C;
    char pad2E[2];
};

struct Tab4F614 {
    char pad0[3];
    unsigned char unk3;
    unsigned char unk4;
    char pad5[7];
};

extern struct Tab4FB00 gUnknown_0804FB00[];
extern struct Tab4F614 gUnknown_0804F614[];
extern unsigned char gUnknown_08047FE4[];
extern int gUnknown_08057A1C[];

extern void *sub_08000234(void);
extern void sub_08000844(void *obj);
extern void sub_08000AD4(void *arg0, int arg1, int arg2);
extern void sub_08000B04(void *arg0, int arg1, unsigned char arg2);
extern void sub_08000D7C(void *arg0, int arg1, int arg2);
extern void sub_08000F24(void *p);
extern void sub_08002138(void *, unsigned int);
extern void sub_080091B8(void);
extern void sub_08009F98(int a, int b, int c);
extern int sub_0801419C(int x, int y);
extern void sub_080144F4(void *arg0);
extern void sub_0803733C(void);
extern void sub_08036AF0(unsigned int obj, unsigned int val);
extern void sub_08038128(void *a, unsigned int b, int c);
extern void sub_08039538(void *arg);
extern int sub_0803BD68(int);
extern void sub_0803BF94(void *obj);

void *sub_0803BDB4(int a, int x, int y, int dir, int mode, int c, int d, int e, int f)
{
    struct Obj3BDB4 *o;
    int v;
    int r6;
    int t;

    o = sub_08000234();
    sub_08039538(o);
    o->unk60 = sub_0803733C;
    o->unkE0 = a;
    o->unkF0 = gUnknown_0804FB00[a].unk2C;
    if (mode != 0x1b)
        o->unk119 = mode;
    else
        o->unk119 = gUnknown_0804F614[a].unk4;
    if (o->unk119 == 9 || o->unk119 == 0x17)
        o->unkF0 |= 0x10;
    if (a == 0x65 || a == 0x61 || a == 0x62 || a == 0x63 || a == 0x67 || a == 0x68 || a == 0x57)
        o->unk90 = sub_080091B8;
    o->unk5C = d;
    sub_08000D7C(o, x, y);
    o->unk40 = sub_0801419C(o->unkC, o->unk10);
    sub_080144F4(o);
    o->unk78 = gUnknown_0804F614[a].unk3;
    t = o->unkB1;
    t &= ~0xC;
    t &= ~0x20;
    o->unkB1 = t;
    o->unk5F = gUnknown_08047FE4[dir] << 5;
    sub_0803BF94(o);
    o->unk103 = f;
    sub_08038128(o, 0, c);
    if (e != 0) {
        sub_08036AF0((unsigned int)o, 0);
    } else {
        o->unkF2 = e;
        sub_08002138(o, 0);
        o->unkE2 = 8;
        sub_08000F24(o);
    }
    r6 = 2;
    v = gUnknown_08057A1C[a];
    if (v != 0 && (unsigned)(a - 0x2c) > 0x18) {
        if ((unsigned)(a - 0x62) <= 1) {
            sub_08009F98(v, 0x50, 0x10);
            r6 = 5;
        } else {
            sub_08009F98(v, 0x40, 8);
            r6 = 4;
        }
    }
    if (sub_0803BD68(o->unkE0)) {
        sub_08000844(o);
        sub_08000B04(o, 0, 4);
        sub_08000AD4(o, 0, r6);
    }
    return o;
}
