void *sub_0801D0AC(const char *a);
extern void *sub_0801D35C(void *r0);
void sub_0801D514(void *arg0, int arg1, short arg2, short arg3, int flags);

struct S0802D408 {
    unsigned char fill0[0x58];
    unsigned int unk58;
    unsigned char unk5C;
    unsigned char fill5D[0x62];
    unsigned char unkBF;
};

void *sub_0802D408(const char *a0, int a1, int a2, int a3)
{
    void *v = sub_0801D0AC(a0);
    struct S0802D408 *ret = sub_0801D35C(&v);

    ret->unk58 = 0x20001;
    ret->unkBF = 0;
    ret->unk5C = 0;
    v = sub_0801D0AC(a0);
    sub_0801D514(ret, (int)v, a1, a2, a3);
    return ret;
}
