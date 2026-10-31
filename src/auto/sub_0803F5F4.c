struct UnkStruct_0803F504 {
    unsigned int unk0;
    unsigned int unk4;
    unsigned short unk8;
    unsigned char unkA;
    unsigned char unkB;
    unsigned char unkC;
    unsigned char unkD;
    unsigned char unkE;
};

void sub_0803F5F4(struct UnkStruct_0803F504 *arg0)
{
    unsigned int unk0;

    if ((arg0->unk4 & 1) == 0)
        return;
    if ((arg0->unk4 & 0x10) == 0)
        return;
    if (arg0->unkD != 0)
    {
        arg0->unkD--;
        return;
    }
    unk0 = arg0->unk0;
    if (((unsigned int *)unk0 + arg0->unkE)[1] == 0)
    {
        arg0->unk4 |= 0x40000;
        if (arg0->unk4 & 0x2000000)
        {
            arg0->unk4 &= -0x11;
            return;
        }
        arg0->unkE = 0;
    }
    else
    {
        arg0->unkE++;
    }
    arg0->unk4 |= 0x80;
    arg0->unkD = arg0->unkC;
}
