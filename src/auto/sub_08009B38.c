extern int sub_08008948(void *a, void *b);
extern unsigned int sub_080097F0(void *a, void *b);
extern void sub_08009A28(void *obj, int val);
extern void sub_080020FC(void *obj, int val);
extern void *sub_08001734(void);

struct Obj {
    unsigned char pad0[0x40];
    int unk40;
    unsigned char pad44[0x14];
    int unk58;
    unsigned char unk5c;
    unsigned char pad5d[0xF];
    void *unk6c;
    unsigned char pad70[8];
    unsigned char unk78;
    unsigned char pad79[0x46];
    unsigned char unkbf;
    unsigned char padC0[0x20];
    unsigned char unke0;
    unsigned char padE1[0x1A];
    unsigned char unkfb;
};

void sub_08009B38(struct Obj *a, struct Obj *b)
{
    unsigned int v;

    if (sub_08008948(a, b) != 0)
        return;
    if (b->unk5c == 0xb) {
        if ((b->unkfb & 4) != 0)
            return;
        sub_080020FC(b, 6);
        b->unk58 &= -5;
        return;
    }
    v = sub_080097F0(a, b);
    if (v <= 1) {
        if (b->unk5c == 1) {
            void *p = sub_08001734();
            if (p != 0)
                sub_08009A28(p, v);
        }
        sub_08009A28(b, v);
        return;
    }
    if (v != 2)
        return;
    if (b->unk5c != 1)
        return;
    if (a->unk5c == 0x14 && a->unke0 == 0xe)
        return;
    b->unk58 |= 0x2000;
    b->unk40 = a->unk40 + (a->unk78 << 16);
    b->unk6c = a;
    b->unkbf = 0x7f;
}
