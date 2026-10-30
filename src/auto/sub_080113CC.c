extern unsigned short gUnknown_03003430[];

typedef struct Obj {
    unsigned char pad0[12];
    unsigned int f12;
    unsigned int f16;
    unsigned char pad1[0x5F - 0x14];
    unsigned char f5F;
    unsigned char pad2[0xE0 - 0x60];
    unsigned char fE0;
    unsigned char pad3[2];
    unsigned char fE3;
} Obj;

struct Obj *sub_0802AD08(struct Obj *p, unsigned int a, unsigned int b);
int sub_080015E0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, int e);

void sub_080113CC(struct Obj *p)
{
    struct Obj *q;
    unsigned int a0;
    unsigned int a1;
    unsigned int hi;
    if ((gUnknown_03003430[0] & 0xF0) != 0)
        return;
    if (p->fE0 == 0x33)
        q = sub_0802AD08(p, 0x6E, 0xF0 << 14);
    else
        q = sub_0802AD08(p, 0x5A, 0xC8 << 14);
    if (q == 0)
        return;
    a0 = p->f12;
    a1 = p->f16;
    hi = q->f16;
    p->f5F = (unsigned char)(((unsigned int)(sub_080015E0(a0, a1, q->f12, hi, 0) + 0x10) & 0xFF) >> 5);
    p->fE3 |= 0x10;
}
