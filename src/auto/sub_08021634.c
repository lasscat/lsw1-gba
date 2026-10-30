extern void sub_08000FA4(void *r0, int r1, int r2, int r3);
extern unsigned char *gUnknown_030069D8;

struct Unk_08021634
{
    int field_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
};

void sub_08021634(struct Unk_08021634 *r0, int r1, int r2, int r3, int r4, int r5)
{
    r0->field_0C = r1;
    r0->field_10 = r3;
    sub_08000FA4(r0, r2, r4, 0x50000);
    *(unsigned int *)(gUnknown_030069D8 + 0x70) = r4 + r5;
}
