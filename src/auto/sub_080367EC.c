struct unk {
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

void sub_080367EC(struct unk *r0)
{
    r0->unkA0[0x41] = 0x32;
    sub_080020FC(r0, 0);
}
