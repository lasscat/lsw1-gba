extern unsigned int gUnknown_0300340C;
extern unsigned int sub_08013254(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sub_080365D8(void *);
extern void sub_08036DA0(void *);

struct Unk1 {
    unsigned char pad0[12];
    unsigned int field_c;
    unsigned int field_10;
};

struct Unk2 {
    unsigned char pad0[12];
    unsigned int field_c;
    unsigned int field_10;
};

void sub_08036FC8(struct Unk1 *arg)
{
    struct Unk1 *r4 = arg;
    unsigned int r0 = r4->field_c;
    unsigned int r1 = r4->field_10;
    struct Unk2 *p = (struct Unk2 *)gUnknown_0300340C;
    unsigned int r3 = p->field_10;
    unsigned int r2v = p->field_c;
    unsigned int ret = sub_08013254(r0, r1, r2v, r3);
    if ((ret >> 16) < *(unsigned char *)((unsigned char *)r4 + 0x115))
        sub_08036DA0(r4);
    else
        sub_080365D8(r4);
}
