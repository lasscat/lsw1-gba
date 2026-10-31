extern unsigned int gUnknown_03007014;

typedef struct
{
    unsigned char unk_00[0x58];
    unsigned int unk_58;
    unsigned char unk_5C[3];
    unsigned char unk_5F;
} Struct379F4;

void sub_080379F4(Struct379F4 *p)
{
    if (p->unk_58 & 0x40000000)
        gUnknown_03007014 = p->unk_5F >> 1;
    else if (p->unk_58 & 0x80000000)
        gUnknown_03007014 = ((p->unk_5F + 16) & 0xFF) >> 5;
    else
    {
        if (p->unk_5F > 7)
            p->unk_5F = 0;
        gUnknown_03007014 = p->unk_5F;
    }
}
