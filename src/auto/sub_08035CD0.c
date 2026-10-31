struct Sub35CD0 {
    int unk00[3];
    int unk0C;
    int unk10;
};
struct Inner35CD0 {
    int unk00[3];
    int unk0C;
    int unk10;
    int unk14[11];
    int unk40;
    int unk44[8];
    int unk64;
};
struct Outer35CD0 {
    int unk00[3];
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C[9];
    int unk40;
    int unk44[9];
    struct Inner35CD0 *unk68;
    int unk6C[3];
    unsigned char unk78;
    unsigned char unk79[163];
    unsigned int unk11C;
};
int sub_080393C4(struct Outer35CD0 *p, unsigned char x);
void sub_08035CD0(struct Outer35CD0 *p)
{
    struct Inner35CD0 *q;
    struct Sub35CD0 *r;
    int a;
    int b;
    p->unk40 = p->unk68->unk40 + 0x1E0000;
    p->unk78 = 10;
    q = p->unk68;
    r = (struct Sub35CD0 *)q->unk64;
    a = q->unk0C;
    a -= (a - r->unk0C) >> 1;
    p->unk0C = a;
    p->unk14 = a;
    r = (struct Sub35CD0 *)q->unk64;
    b = q->unk10;
    b -= (b - r->unk10) >> 1;
    p->unk0C = b;
    p->unk18 = b;
    p->unk11C = sub_080393C4(p, 62);
}
