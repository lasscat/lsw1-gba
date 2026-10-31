struct UnkStruct_0803C160 {
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

struct UnkStruct_0803C160Ret {
    char pad0[0x58];
    int unk58;
    char pad5C[0x30];
    void (*unk8C)(void);
    char pad90[0x44];
    int unkD4;
    char padD8[8];
    unsigned char unkE0;
    char padE1[0x11];
    unsigned short unkF2;
    char padF4[0x11];
    unsigned char unk105;
    char pad106[4];
    unsigned char unk10A;
};

extern void *sub_0803BDB4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6,
                          unsigned short arg7, int arg8);
extern void sub_08009A58(void);
extern unsigned char gUnknown_03006B1C[];

void *sub_0803C160(struct UnkStruct_0803C160 *ptr)
{
    struct UnkStruct_0803C160Ret *ret;

    ret = sub_0803BDB4(ptr->unk8, ptr->unk4 << 16, ptr->unk6 << 16, ptr->unk9, ptr->unkA, 0, 7,
                       ptr->unkB == 0, ptr->unkE);
    ret->unk58 |= 0x40;
    if (ptr->unkB != 0)
        ret->unkD4 |= 0x20;
    ret->unk10A = ptr->unkC;
    ret->unk105 = ptr->unkD;
    ret->unk8C = sub_08009A58;
    if (gUnknown_03006B1C[0x293] == 0x1a && ret->unkE0 == 7)
        ret->unk58 &= ~0x40;
    ret->unkF2 &= 0xFFF7;
    return ret;
}
