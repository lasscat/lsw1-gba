struct UnkStruct_0803C3B0 {
    int unk0;
    unsigned short unk4;
    unsigned short unk6;
    unsigned char unk8;
    unsigned char unk9;
    unsigned char unkA;
    unsigned char unkB;
};

extern void *sub_0803BDB4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6,
                          unsigned short arg7, int arg8);

void *sub_0803C3B0(struct UnkStruct_0803C3B0 *ptr)
{
    return sub_0803BDB4(ptr->unk8 + 0x69, ptr->unk4 << 16, ptr->unk6 << 16, ptr->unk9, ptr->unkA, 0,
                       8, 1, ptr->unkB);
}
