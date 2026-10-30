struct Sub42328
{
    unsigned char unk00[0x58];
    unsigned int unk58;
    unsigned char unk5C[0x85];
    unsigned char unkE1;
    unsigned char unkE2[0x1F];
    unsigned char unk101;
};

void sub_08042328(struct Sub42328 *p)
{
    if (p->unk101 != 0)
        p->unk101--;
    if (p->unkE1 == 1)
        p->unk58 |= 2;
}
