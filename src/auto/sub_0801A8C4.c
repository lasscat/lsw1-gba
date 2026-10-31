extern unsigned int *gUnknown_03004E54;
extern unsigned int gUnknown_03004E34[];
extern unsigned char gUnknown_030049F0[];
extern unsigned char gUnknown_03004E10[];

unsigned int sub_0800DF9C(unsigned int *arg0);
void *sub_08013538(int);
void sub_0800DFFC(void *, void *);

void sub_0801A8C4(unsigned int *arg0)
{
    unsigned int *p;

    gUnknown_03004E54 = p = (unsigned int *)sub_08013538(sub_0800DF9C(arg0));
    gUnknown_03004E34[0] = (unsigned int)p + 4;
    sub_0800DFFC(arg0, p);
    gUnknown_030049F0[0x2A0] = 0;
    gUnknown_03004E10[0] &= 0xFC;
    *(unsigned int *)&gUnknown_03004E10[12] = 0x10000;
    *(unsigned int *)&gUnknown_03004E10[16] = 0x10000;
    *(unsigned int *)&gUnknown_03004E10[4] = 0x10000;
    *(unsigned int *)&gUnknown_03004E10[8] = 0x10000;
}
