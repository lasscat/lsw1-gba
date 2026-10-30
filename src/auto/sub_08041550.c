extern unsigned short gUnknown_03006B1C[];

void sub_080414F4(unsigned int, void *, int);

struct S41550
{
    unsigned char unk0;
    unsigned char pad1[3];
    unsigned short unk4;
    unsigned short pad6;
    unsigned int unk8;
    unsigned int unkC;
    void *unk10;
};

void sub_08041550(struct S41550 *p)
{
    if (p->unk4 != gUnknown_03006B1C[0x1D8])
    {
        p->unk4 = gUnknown_03006B1C[0x1D8];
        sub_080414F4(gUnknown_03006B1C[0x1D8], p->unk10, 3);
    }
    p->unk0 = 2;
}
