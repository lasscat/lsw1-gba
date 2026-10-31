void *sub_08000234(void);

extern void *gUnknown_080516F8[];

struct obj_0802AFC8 {
    unsigned char unk00[0x58];
    unsigned int unk58;
    unsigned char unk5C;
    unsigned char unk5D[3];
    void *unk60;
    unsigned char unk64[0x7c];
    unsigned char unkE0;
    unsigned char unkE1;
};

void *sub_0802AFC8(int arg0)
{
    struct obj_0802AFC8 *r3 = sub_08000234();
    r3->unk5C = 0x2c;
    r3->unk58 = 0x808;
    r3->unkE0 = arg0;
    r3->unkE1 = 0;
    r3->unk60 = gUnknown_080516F8[arg0];
    return r3;
}
