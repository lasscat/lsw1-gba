struct unk
{
    unsigned char unk00[0x58];
    unsigned int flags;
    unsigned char unk5C[0x40];
    unsigned int unk9C;
    unsigned char unkA0[0x42];
    unsigned char unkE2;
    unsigned char unkE3;
    unsigned char unkE4[0x14];
    unsigned char unkF8;
};

extern void sub_080020FC(struct unk *obj, int val);

void sub_0803AB34(struct unk *r0)
{
    struct unk *r4 = r0;
    sub_080020FC(r4, 2);
    r4->unkF8 = 2;
    r4->unk9C = 0;
    r4->unkE3 |= 8;
    r4->flags &= -0x41;
}
