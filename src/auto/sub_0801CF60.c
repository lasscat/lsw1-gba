extern unsigned int gUnknown_03006B14;
extern void *gUnknown_0300340C;

extern void sub_08002138(void *, unsigned int);
extern void sub_080020FC(void *, int);
extern void sub_08000F24(void *);
extern void sub_08018840(unsigned short, unsigned int);

struct Obj {
    unsigned char pad00[0x40];
    unsigned int unk40;
    unsigned char pad44[0x14];
    unsigned int unk58;
    unsigned char unk5c;
    unsigned char pad5d[0x0b];
    void *unk68;
    unsigned char pad6c[0x68];
    unsigned int unkd4;
    unsigned char padd8[0x09];
    unsigned char unke1;
    unsigned char unke2;
};

void sub_0801CF60(struct Obj *a, struct Obj *b)
{
    unsigned int v;
    void *p;
    if (b->unk5c != 1)
        return;
    if (a->unk40 != b->unk40)
        return;
    if ((b->unkd4 & 0x200) != 0)
        return;
    v = b->unke2;
    if (v == 0x19 || v == 0x0a || v == 0x3e || v == 0x3f)
        return;
    gUnknown_03006B14 |= 0x10;
    a->unk58 &= ~4;
    a->unk68 = b;
    p = gUnknown_0300340C;
    sub_08002138(p, 3);
    ((struct Obj *)gUnknown_0300340C)->unkd4 |= 4;
    sub_080020FC(gUnknown_0300340C, 2);
    sub_08000F24(gUnknown_0300340C);
    sub_08018840(0x3f, 2);
    a->unk58 |= 8;
    a->unke1 = 4;
}
