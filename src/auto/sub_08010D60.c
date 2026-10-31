extern unsigned int gUnknown_0300340C;
extern unsigned char gUnknown_03006B1C[];

extern void sub_0802D640(void);
extern void sub_0801C19C(unsigned int arg);
extern void sub_08000F24(void *p);
extern void sub_080020FC(void *obj, int val);
extern void sub_08002138(void *arg0, unsigned int arg1);
extern void sub_0802E2CC(void *p);

struct State {
    unsigned char _00[0x8C];
    unsigned int unk8C;
    unsigned char _90[0x1C];
    unsigned int unkAC;
    unsigned char _B0[0x0F];
    signed char idxBF;
    unsigned char table[4];
};

extern struct State gUnknown_0300332C;

struct Obj {
    unsigned char _00[0x58];
    unsigned int unk58;
    unsigned char _5C[0x7C];
    unsigned short unkD8;
};

void sub_08010D60(struct Obj *p)
{
    struct State *base;
    unsigned int flag;
    sub_0802D640();
    base = &gUnknown_0300332C;
    if (base->unkAC != 0) {
        sub_0801C19C(base->unkAC);
        base->unkAC = 0;
    }
    flag = base->unk8C & 1;
    if (flag != 0) {
        p->unkD8 = 0;
        sub_08000F24(p);
        p->unk58 |= 0x40;
        sub_0802E2CC((void *)gUnknown_0300340C);
        sub_080020FC(p, 0x50);
    } else {
        gUnknown_03006B1C[0x29D] = base->table[base->idxBF];
        p->unkD8 = flag;
        sub_08000F24(p);
        p->unk58 &= ~4;
        sub_0802E2CC((void *)gUnknown_0300340C);
        sub_08002138(p, 0x18);
        sub_080020FC(p, 6);
    }
}
