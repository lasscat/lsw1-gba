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

void sub_0803F504(struct UnkStruct_0803F504 *arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4, unsigned short arg5)
{
    arg0->unk0 = arg1;
    arg0->unk4 = arg0->unk4 | 0x80;
    arg0->unkC = arg2;
    arg0->unkD = arg2;
    arg0->unkA = arg3;
    arg0->unkB = arg4;
    arg0->unk8 = arg5;
    arg0->unkE = 0;
}
