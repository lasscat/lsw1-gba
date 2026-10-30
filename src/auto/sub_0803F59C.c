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

int sub_08005B3C(int a, void *b, unsigned short c, unsigned short d, int e, int f);

void sub_0803F59C(struct UnkStruct_0803F504 *arg0)
{
    if ((arg0->unk4 & 0x81) == 0x81)
    {
        arg0->unk4 &= -0x81;
        sub_08005B3C(3, *(void **)((unsigned int *)arg0->unk0 + arg0->unkE), arg0->unk8, 0, arg0->unkA, arg0->unkB);
    }
}
