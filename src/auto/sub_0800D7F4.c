extern unsigned int sub_08004A5C(unsigned char, unsigned char);
extern void sub_0800FD8C(int arg0, int arg1);
extern void sub_08010468(void *p);
extern int sub_080111E4(int a);
extern void sub_080116BC(void);
extern void sub_080144F4(void *arg0);
extern void sub_080157AC(void *arg0);
extern void sub_08015810(void *arg0);
extern void sub_080378D4(unsigned char *p);
extern void sub_08037AB0(void *arg0, int arg1, int arg2);
extern void sub_0803BD08(void *p);

struct State {
    unsigned char _00[0xBF];
    signed char idxBF;
    unsigned char table[4];
};

struct Obj {
    unsigned char _00[0xC];
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    unsigned char _1C[0x24];
    int unk40;
    unsigned char _44[0x14];
    unsigned int unk58;
    unsigned char _5C[3];
    unsigned char b5F;
    unsigned char _60[0x4C];
    int unkAC;
    unsigned char _B0[0xC];
    unsigned short unkBC;
    unsigned char _BE[0x22];
    unsigned char bE0;
    unsigned char _E1[2];
    unsigned char bE3;
    unsigned char _E4[0xE];
    unsigned short unkF2;
};

extern struct Obj *gUnknown_0300340C;
extern struct State gUnknown_0300332C;
extern unsigned char gUnknown_0804F5A8[];
extern unsigned int gUnknown_03007014;
extern unsigned char gUnknown_03006B1C[];
extern unsigned char gUnknown_03006F94;

void sub_0800D7F4(void *arg)
{
    unsigned char *a = arg;
    struct Obj *p;
    int t0, t1, t2;

    p = (struct Obj *)sub_08004A5C(a[4], a[5]);
    *(struct Obj **)((unsigned char *)gUnknown_0300340C + 0x64) = p;
    sub_080116BC();
    gUnknown_0300332C.idxBF = sub_080111E4(gUnknown_0804F5A8[p->bE0]);
    p->bE0 = gUnknown_0300340C->bE0;
    p->bE3 |= 0x12;
    sub_080157AC(p);
    p->unkAC = 0;
    p->unkBC &= 0xFDFF;
    sub_0803BD08(p);
    if (p->unk58 & 0x400)
        sub_08015810(p);
    gUnknown_03007014 = ((unsigned char *)gUnknown_0300340C)[0x5F];
    p->unkF2 &= 0xFF7F;
    sub_08037AB0(p, 0x19, 0);
    sub_080378D4((unsigned char *)p);
    gUnknown_03006B1C[0x29A] |= 8;
    {
        unsigned int old = p->b5F;
        p->b5F = gUnknown_0300340C->b5F << 5;
        gUnknown_0300340C->b5F = ((old + 0x10) & 0xFF) >> 5;
    }
    sub_0800FD8C(gUnknown_0300332C.table[gUnknown_0300332C.idxBF], 1);
    sub_08015810(gUnknown_0300340C);
    sub_08010468(gUnknown_0300340C);
    t0 = p->unkC;
    t1 = p->unk10;
    t2 = p->unk40;
    {
        struct Obj *q = gUnknown_0300340C;
        int x = q->unkC;
        int y = q->unk10;
        p->unkC = x;
        p->unk10 = y;
        p->unk14 = x;
        p->unk18 = y;
        p->unk40 = q->unk40;
        q->unkC = t0;
        q->unk10 = t1;
        q->unk14 = t0;
        q->unk18 = t1;
        q->unk40 = t2;
        sub_080144F4(q);
    }
    gUnknown_03006F94 = gUnknown_0300332C.idxBF;
}
