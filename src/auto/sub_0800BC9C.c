extern unsigned int sub_08004A5C(unsigned char, unsigned char);
extern void sub_0802AC3C(void *, int);
extern int sub_0801419C(int x, int y);

typedef struct {
    unsigned char unk00[4];
    unsigned short unk04;
    unsigned short unk06;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
} Arg0800BC9C;

typedef struct {
    unsigned char unk00[0x0C];
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned char unk1C[0x24];
    int unk40;
    unsigned char unk44[0x18];
    unsigned char unk5C;
    unsigned char unk5D[2];
    unsigned char unk5F;
    unsigned char unk60[0x83];
    unsigned char unkE3;
} Obj0800BC9C;

void sub_0800BC9C(Arg0800BC9C *a)
{
    int x;
    int y;
    Obj0800BC9C *p = (Obj0800BC9C *)sub_08004A5C(a->unk08, a->unk09);

    if (p == 0)
        return;
    x = a->unk04 << 16;
    p->unk0C = x;
    y = a->unk06 << 16;
    p->unk10 = y;
    p->unk14 = x;
    p->unk18 = y;
    p->unkE3 |= 0x10;
    p->unk5F = a->unk0A;
    if (p->unk5C != 1)
        sub_0802AC3C(p, ((p->unk5F + 0x10) & 0xFF) >> 5);
    p->unk40 = sub_0801419C(p->unk0C, p->unk10);
}
