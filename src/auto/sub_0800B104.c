extern unsigned char gUnknown_03002BDC;
extern unsigned int gUnknown_03006B14;
extern void sub_0801C210(int);

struct Sub0800B104 {
    unsigned char unk0[4];
    unsigned char unk4;
};

void sub_0800B104(struct Sub0800B104 *a)
{
    if (gUnknown_03002BDC == 1)
        gUnknown_03006B14 |= 0x1000000;
    sub_0801C210(a->unk4);
}
