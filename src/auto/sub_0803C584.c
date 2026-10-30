struct UnkStruct_0803C584 {
    int unk0;
    unsigned short unk4;
    unsigned short unk6;
    unsigned char unk8;
    unsigned char unk9;
    unsigned char unkA;
    unsigned char unkB;
    unsigned char unkC;
};

extern void *sub_08004A14(unsigned char arg0, unsigned char arg1);
extern void *sub_0803BDB4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6,
                          unsigned short arg7, int arg8);

void *sub_0803C584(unsigned char arg0, unsigned char arg1)
{
    struct UnkStruct_0803C584 *ptr;

    ptr = sub_08004A14(arg0, arg1);
    return sub_0803BDB4(ptr->unk8 + 0x2c, ptr->unk4 << 16, ptr->unk6 << 16, ptr->unk9, ptr->unkA, 0,
                       0x13, ptr->unkC, ptr->unkB);
}
