struct Obj
{
    unsigned char unk00[0x0c];
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned char unk1c[0x3c];
    unsigned int unk58;
    unsigned char unk5c[0x57];
    unsigned char unkB3_0 : 4;
    unsigned char unkB3_4 : 1;
    unsigned char unkB3_5 : 3;
    unsigned char unkB4[0x08];
    unsigned short unkBC;
    unsigned char unkBE[0x1e];
    unsigned short unkDC;
    unsigned char unkDE[4];
    unsigned char unkE2;
    unsigned char unkE3[0x38];
    struct Obj *unk11C;
    struct Obj *unk120;
    struct Obj *unk124;
    unsigned char unk128;
    unsigned char unk129;
    unsigned char unk12A;
};

extern void sub_080144F4(void *arg0);
extern void sub_0801C19C(unsigned int arg);
extern void sub_0801C6AC(unsigned int arg);
extern void sub_08033458(void *arg0, int arg1, int arg2, int arg3);
extern struct Obj *sub_080393C4(int, unsigned char);

void sub_08033D80(struct Obj *a)
{
    struct Obj *o;
    int bit;
    int zero = 0;

    a->unkBC |= 0x20;
    switch (a->unkE2) {
    case 8:
        break;
    case 0x14:
        o = a->unk11C;
        bit = o->unkB3_4;
        if (a->unk12A == 0)
            sub_08033458(o, 0xb, 0, 1);
        else
            sub_08033458(o, 0x13, 0, 1);
        o->unkB3_4 = bit;
        o = a->unk120;
        bit = o->unkB3_4;
        if (a->unk12A == 0)
            sub_08033458(o, 0xc, 0, 1);
        else
            sub_08033458(o, 0x14, 0, 1);
        o->unkB3_4 = bit;
        o = a->unk124;
        o->unk58 |= 4;
        if (o->unk11C == 0)
            o->unk11C = sub_080393C4((int)o, 0x2b);
        o->unkDC = 2;
        a->unkE2 = 3;
        a->unk129 = 8;
        a->unk128 = 0;
        a->unk58 |= 1;
        break;
    case 2:
        o = a->unk11C;
        bit = o->unkB3_4;
        if (a->unk12A == 0)
            sub_08033458(o, 0xd, 0, 1);
        else
            sub_08033458(o, 0x11, 0, 1);
        o->unk58 |= 0x10;
        o->unkB3_4 = bit;
        o = a->unk120;
        bit = o->unkB3_4;
        if (a->unk12A == 0)
            sub_08033458(o, 0xe, 0, 1);
        else
            sub_08033458(o, 0x12, 0, 1);
        o->unk58 |= 0x10;
        o->unkB3_4 = bit;
        o = a->unk124;
        o->unk58 &= ~4;
        sub_0801C6AC((unsigned int)o);
        sub_0801C19C((unsigned int)o->unk11C);
        o->unk11C = 0;
        a->unkE2 = 8;
        a->unk129 = 8;
        a->unk128 = 0;
        a->unk58 &= ~1;
        break;
    case 3:
        o = a->unk124;
        if (o->unkDC != 0)
            o->unkDC--;
        {
            struct Obj *q = a->unk11C;
            struct Obj *r = a->unk120;
            a->unk14 = a->unk0c = q->unk0c + ((r->unk0c - q->unk0c) >> 3) * a->unk128;
            a->unk18 = a->unk10 = q->unk10 + ((r->unk10 - q->unk10) >> 3) * a->unk128;
        }
        a->unk128++;
        if (a->unk128 >= a->unk129)
            a->unk128 = zero;
        sub_080144F4(a);
        break;
    }
}
