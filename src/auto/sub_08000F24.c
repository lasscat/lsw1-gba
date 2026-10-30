/* Placeholder names */
struct Unknown
{
    unsigned char unk00[0x24];
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    unsigned char unk34[0x10];
    int unk44;
};

void sub_08000F24(struct Unknown *p)
{
    p->unk2c = 0;
    p->unk30 = 0;
    p->unk24 = 0;
    p->unk28 = 0;
    p->unk44 = 0;
}
