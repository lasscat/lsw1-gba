struct Obj {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    unsigned char pad2C[48];
    unsigned char unk5C;
    unsigned char pad5D[131];
    unsigned char unkE0;
};

extern int sub_08008948(void *arg0, void *arg1);
extern unsigned int sub_080097F0(void *arg0, void *arg1);
extern void sub_08009A28(void *arg0, unsigned int arg1);
extern void *sub_08001734(void);
extern int sub_0802ADF0(void *arg);
extern void sub_080020FC(void *obj, int val);
extern void sub_08036AF0(void *obj, unsigned int val);

void sub_08009A58(struct Obj *a, struct Obj *b)
{
    unsigned char c;
    unsigned int t;
    void *p;

    if (sub_08008948(a, b) != 0)
        return;
    if (b->unk5C == 0xc) {
        c = a->unkE0;
        c -= 0x67;
        if (c <= 1) {
            t = sub_080097F0(a, b);
            if (t > 1)
                return;
            sub_08009A28(b, t);
            return;
        }
    }
    if (b->unk5C != 1)
        return;
    if (sub_080097F0(a, b) > 1)
        goto skip;
    p = sub_08001734();
    if (p != 0) {
        *(int *)((char *)p + 0x14) = b->unkC;
        *(int *)((char *)p + 0x18) = b->unk10;
    }
    b->unk14 = b->unkC;
    b->unk18 = b->unk10;
    b->unk24 = 0;
    b->unk28 = 0;
skip:
    t = sub_080097F0(b, a);
    if (t > 1)
        return;
    c = a->unkE0;
    if (c == 0x5c || c == 0x63 || c == 0x62 || c == 0x61 || c == 0x65)
        return;
    a->unk14 = a->unkC;
    a->unk18 = a->unk10;
    if (sub_0802ADF0(a) != 0)
        sub_080020FC(a, 2);
    else
        sub_08036AF0(a, 1);
}
