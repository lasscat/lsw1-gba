struct UnkStruct_0803C3B0 {
    int unk0;
    unsigned short unk4;
    unsigned short unk6;
    unsigned char unk8;
    unsigned char unk9;
    unsigned char unkA;
    unsigned char unkB;
};
struct UnkRet_0803C430 {
    char unk0[0xC];
    int unkC;
    int unk10;
    char unk14[0x44];
    int unk58;
    char unk5C[0x30];
    void (*unk8C)(void);
    char unk90[0x44];
    int unkD4;
    char unkD8[8];
    unsigned char unkE0;
    char unkE1[0x11];
    unsigned short unkF2;
};
extern void *sub_0803BDB4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6,
                          unsigned short arg7, int arg8);
extern void sub_08009A58(void);
extern void *sub_08033374(int a, int b);
extern void sub_080438A0(int a, int b, int c, void *d, int e);
void *sub_0803C430(struct UnkStruct_0803C3B0 *ptr)
{
    struct UnkRet_0803C430 *r = sub_0803BDB4(ptr->unk8 + 0x45, ptr->unk4 << 16, ptr->unk6 << 16,
        ptr->unk9, ptr->unkA, 0, 12, 1, ptr->unkB);
    r->unk8C = sub_08009A58;
    if (r->unkE0 == 0x54) {
        sub_08033374((int)r, 0x37);
    } else if (r->unkE0 == 0x67 || r->unkE0 == 0x68) {
        r->unkF2 &= 0xFFF7;
        r->unk58 = (r->unk58 | 0x40) & 0xFFFFFDFB;
        r->unkD4 |= 0x80;
    } else if (r->unkE0 == 0x45 || r->unkE0 == 0x47 || r->unkE0 == 0x46) {
        sub_08033374((int)r, 0x24);
        sub_080438A0(r->unkC, r->unk10, 0x23, r, 0);
        r->unkD4 |= 0x80;
    }
    return r;
}
