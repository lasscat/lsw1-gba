struct UnkStruct_0803C330 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
};

struct UnkStruct_0803BDB4Ret {
    char pad[0x8C];
    void (*unk8C)(void);
};

extern void *sub_0803BDB4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6,
                          unsigned short arg7, int arg8);
extern void sub_08009A58(void);

void *sub_0803C330(struct UnkStruct_0803C330 *arg0)
{
    struct UnkStruct_0803BDB4Ret *ptr;

    ptr = sub_0803BDB4(0x66, arg0->unkC, arg0->unk10, 3, 0x1b, 0, 0xc, 1, 0);
    ptr->unk8C = sub_08009A58;
    return ptr;
}
