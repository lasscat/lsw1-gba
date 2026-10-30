struct Sub0801EBA8Inner {
    unsigned short unk0;
    unsigned short unk2;
    unsigned char unk4[8];
    int unkC;
    int unk10;
    unsigned char unk14[8];
};

struct Sub0801EBA8Outer {
    unsigned char unk0[4];
    struct Sub0801EBA8Inner inners[2];
};

extern struct Sub0801EBA8Outer gUnknown_03006924[];

void sub_0801EBA8(int a, int b, int c, int d)
{
    struct Sub0801EBA8Outer *o = &gUnknown_03006924[a];
    struct Sub0801EBA8Inner *p = &o->inners[b];
    p->unkC = c;
    p->unk10 = d;
    p->unk0 |= 2;
}
