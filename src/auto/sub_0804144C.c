struct UnkStruct_0802D3AC {
    unsigned int unk0;
    unsigned int unk4;
};

struct S41550 {
    unsigned char unk0;
    unsigned char pad1[3];
    unsigned short unk4;
    unsigned short pad6;
    unsigned int unk8;
    unsigned int unkC;
    void *unk10;
};

struct Sub0804144C {
    unsigned char unk0;
    unsigned char pad1[3];
    unsigned short unk4;
    unsigned short unk6;
    unsigned short unk8;
    unsigned short unkA;
    struct UnkStruct_0802D3AC *unkC;
    void *unk10;
    void *unk14;
    void *unk18;
};

extern struct UnkStruct_0802D3AC *sub_0802D3AC(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4);
extern unsigned short gUnknown_03006B1C[];
extern void sub_080414F4(unsigned int arg0, void *arg1, int arg2);
extern void sub_08041550(struct S41550 *p);

void sub_0804144C(struct Sub0804144C *arg0)
{
    struct UnkStruct_0802D3AC *p;
    unsigned short v;

    p = sub_0802D3AC(0x08070350, 2, 0x1B, 0, 1);
    arg0->unkC = p;
    p->unk4 |= 0x10;
    arg0->unk10 = sub_0802D3AC(0x080703A4, 2, 0x1A, 0, 0xA);
    arg0->unk14 = sub_0802D3AC(0x080703A4, 2, 0x19, 0, 0xD);
    arg0->unk18 = sub_0802D3AC(0x080703A4, 2, 0x18, 0, 0x10);
    v = gUnknown_03006B1C[0x1D8];
    arg0->unk4 = v;
    arg0->unk6 = v;
    arg0->unk8 = 0;
    sub_080414F4(gUnknown_03006B1C[0x1D8], arg0->unk10, 3);
    sub_08041550((struct S41550 *)arg0);
}
