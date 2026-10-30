struct unk
{
    unsigned char unk00[0xdc];
    unsigned short unkDC;
    unsigned char unkDE[3];
    unsigned char unkE1;
    unsigned char unkE2[0x1d];
    unsigned char unkFF;
};

extern void sub_080020FC(struct unk *obj, int val);

void sub_080367A8(struct unk *r0)
{
    struct unk *r4 = r0;
    r4->unkE1 = 0x1b;
    sub_080020FC(r4, 0);
    r4->unkDC = 0x1e;
    r4->unkFF = 0x1e;
}
