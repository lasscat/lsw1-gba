extern void sub_08007B04(int a, unsigned char b, unsigned char c);

struct Obj08218 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14[17];
    int unk58;
};

struct G6B1C {
    int unk0;
    int unk4;
    struct Obj08218 *p8;
};

struct G332C {
    unsigned char f[188];
    unsigned char bBC;
    unsigned char bBD;
};

extern struct G6B1C gUnknown_03006B1C;
extern struct G332C gUnknown_0300332C;
extern struct Obj08218 *gUnknown_0300340C;

void sub_08008218(void)
{
    struct Obj08218 *p = gUnknown_03006B1C.p8;
    int flags;
    struct Obj08218 *q;
    int d;

    if (p == 0)
        return;
    flags = p->unk58;
    if ((flags & 2) != 0) {
        gUnknown_03006B1C.p8 = 0;
        gUnknown_0300332C.bBC = 0;
        gUnknown_0300332C.bBD = 0;
        return;
    }
    if ((flags & 0x400) != 0 && (q = gUnknown_0300340C, q->unk10 <= p->unk10)) {
        gUnknown_0300332C.bBC = 1;
        d = q->unkC - p->unkC;
        if (d < 0)
            d = -d;
        if (d <= 0x77FFFF)
            gUnknown_0300332C.bBD = 1;
        else
            sub_08007B04(0, 0, 0);
    } else {
        gUnknown_0300332C.bBC = 0;
        gUnknown_0300332C.bBD = 0;
    }
}
