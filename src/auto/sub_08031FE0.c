struct Sub {
    unsigned char pad0[0xC];
    unsigned int unk0C;
    unsigned int unk10;
};

struct unk {
    unsigned char pad00[0xC];
    unsigned int unk0C;
    unsigned int unk10;
    unsigned char pad14[0x5F - 0x14];
    unsigned char unk5F;
    unsigned char pad60[0x64 - 0x60];
    struct Sub *unk64;
    unsigned char pad68[0xE2 - 0x68];
    unsigned char unkE2;
    unsigned char padE3[0x11C - 0xE3];
    unsigned short unk11C;
    unsigned char unk11E;
};

extern unsigned int gUnknown_0300340C;
int sub_080015E0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, int e);
void sub_080020FC(struct unk *obj, int val);
void sub_08036AF0(unsigned int obj, unsigned int val);
void sub_0803ABE0(struct unk *obj);

void sub_08031FE0(struct unk *p)
{
    unsigned int state;
    unsigned int d;
    int ret;
    if (p->unkE2 == 0)
        sub_080020FC(p, 3);
    state = p->unkE2;
    if (state == 3) {
        if (p->unk64 == 0)
            p->unk64 = (struct Sub *)gUnknown_0300340C;
        ret = sub_080015E0(p->unk0C, p->unk10, (d = p->unk64->unk10, p->unk64->unk0C), d, p->unk11E << 16);
        if (ret == 0x100)
            state = 2;
        else if (p->unk11C == 0)
            state = 2;
        else if (p->unk5F != ret)
            p->unk5F = ret;
        p->unk11C--;
    } else {
        sub_0803ABE0(p);
    }
    if (state == 2)
        sub_08036AF0((unsigned int)p, 0);
}
