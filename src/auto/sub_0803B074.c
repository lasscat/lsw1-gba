struct unk
{
    unsigned char pad0[0x58];
    unsigned int flags;
    unsigned char pad1[0x80];
    unsigned short atDC;
    unsigned char pad2[0x4A];
    unsigned char at128;
    unsigned char at129;
    unsigned char at12A;
};

extern void sub_08004458(int, int);

void sub_0803B074(struct unk *r0)
{
    struct unk *r4 = r0;
    if (r4->at129 != 0)
    {
        unsigned char x = r4->at12A;
        sub_08004458(0, x);
        r4->pad2[4] = 0x58;
        r4->atDC = r4->at128;
        r4->flags |= 0x800;
    }
}
