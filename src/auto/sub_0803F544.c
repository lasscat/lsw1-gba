struct UnkStruct_0803F544 {
    unsigned int unk0;
    unsigned int unk4;
    unsigned short unk8;
    unsigned char unkA;
    unsigned char unkB;
    unsigned char unkC;
    unsigned char unkD;
    unsigned char unkE;
};

void sub_0803F544(struct UnkStruct_0803F544 *arg0, unsigned int arg1, unsigned int arg2)
{
    arg0->unk0 = arg1;
    arg0->unk4 = arg0->unk4 | 0x80;
    arg0->unkC = arg2;
    arg0->unkD = arg2;
    arg0->unkE = 0;
}
