struct UnkStruct_0802D3AC {
    unsigned int unk0;
    unsigned int unk4;
};

extern struct UnkStruct_0802D3AC *sub_0803F49C(void);
extern void sub_0803F504(struct UnkStruct_0802D3AC *arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4, unsigned int arg5);

struct UnkStruct_0802D3AC *sub_0802D3AC(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4)
{
    struct UnkStruct_0802D3AC *result;

    result = sub_0803F49C();
    result->unk4 = 0x00020001;
    if (arg0 != 0) {
        sub_0803F504(result, arg0, arg1, arg2, arg3, arg4);
    }
    return result;
}
