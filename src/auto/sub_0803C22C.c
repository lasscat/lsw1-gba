struct UnkStruct_0803C22C {
    int unk0;
    unsigned short unk4;
    unsigned short unk6;
    unsigned char unk8;
    unsigned char unk9;
    unsigned char unkA;
    unsigned char unkB;
    unsigned char unkC;
    unsigned char unkD;
    unsigned char unkE;
};

struct UnkStruct_0803BDB4Ret {
    char pad0[0x58];
    int unk58;
    char pad5C[0x30];
    void (*unk8C)(void);
    char pad90[0x44];
    int unkD4;
    char padD8[0x2D];
    unsigned char unk105;
    char pad106[3];
    unsigned char unk109;
};

extern void *sub_08004A14(unsigned char arg0, unsigned char arg1);
extern void *sub_0803BDB4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6,
                          unsigned short arg7, int arg8);
extern void sub_08008994(void);
extern void sub_08009A58(void);

void *sub_0803C22C(unsigned char arg0, unsigned char arg1)
{
    struct UnkStruct_0803C22C *ptr;
    struct UnkStruct_0803BDB4Ret *ret;

    ptr = sub_08004A14(arg0, arg1);
    ret = sub_0803BDB4(ptr->unk8 + 0x1c, ptr->unk4 << 16, ptr->unk6 << 16, ptr->unk9, ptr->unkA, 0,
                       0x1c, 0, ptr->unkC);
    ret->unk58 |= 0x40;
    ret->unkD4 |= 0x20;
    ret->unk8C = sub_08008994;
    ret->unk105 = ptr->unkB;
    ret->unk109 = ptr->unkE;
    ret->unk8C = sub_08009A58;
    return ret;
}
