struct unk35984
{
    unsigned char unk00[0x0C];
    unsigned int unk0C;
    unsigned int unk10;
    unsigned char unk14[0x2C];
    unsigned int unk40;
    unsigned char unk44[0x24];
    struct unk35984 *unk68;
    unsigned char unk6C[0x49];
    unsigned char unkB5;
    unsigned char unkB6[9];
    unsigned char unkBF;
    unsigned char unkC0[0x1C];
    unsigned short unkDC;
};
void sub_08035984(struct unk35984 *p)
{
    unsigned int src = p->unk68->unkB5;
    unsigned int cur = p->unkB5;
    int mask = 13;

    unsigned int keep = src & 12;
    unsigned int rest = cur & -mask;
    p->unkB5 = rest | keep;
    p->unkBF = 5;
    p->unk0C = p->unk68->unk0C;
    p->unk10 = p->unk68->unk10;
    p->unkDC = 28;
}
