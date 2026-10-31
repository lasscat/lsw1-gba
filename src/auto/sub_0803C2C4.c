struct UnkStruct_0803C2C4 {
    char pad0[0xC];
    int unkC;
    int unk10;
    char pad14[0x4B];
    unsigned char unk5F;
    char pad60[0xA3];
    unsigned char unk103;
};

struct UnkStruct_0803BDB4Ret {
    char pad[0x8C];
    void (*unk8C)(void);
    char pad90[0x73];
    unsigned char unk103;
};

extern void *sub_0803BDB4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6,
                          unsigned short arg7, int arg8);
extern void sub_08009A58(void);

void *sub_0803C2C4(struct UnkStruct_0803C2C4 *arg0)
{
    struct UnkStruct_0803BDB4Ret *ptr;

    ptr = sub_0803BDB4(0x49, arg0->unkC, arg0->unk10, ((arg0->unk5F + 0x10) & 0xFF) >> 5, 0x1b, 0, 0xc, 1, 0);
    ptr->unk8C = sub_08009A58;
    ptr->unk103 = arg0->unk103;
    return ptr;
}
