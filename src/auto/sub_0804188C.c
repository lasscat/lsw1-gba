struct UnkStruct_0802D3AC {
    unsigned int unk0;
    unsigned int unk4;
};

struct Sub0804188C {
    unsigned char unk0;
    unsigned char unk1;
    unsigned char unk2;
    unsigned char unk3;
    struct UnkStruct_0802D3AC *unk4;
    unsigned short unk8;
};

extern struct UnkStruct_0802D3AC *sub_0802D3AC(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4);
extern void sub_08041994(void *arg);
void sub_0804188C(struct Sub0804188C *arg0)
{
    unsigned int arg4 = 0x3d;
    unsigned short zero = 0;
    arg0->unk4 = sub_0802D3AC(0x080703D0, 2, 0, 2, arg4);
    arg0->unk8 = zero;
    sub_08041994(arg0);
    arg0->unk0 = 2;
}
