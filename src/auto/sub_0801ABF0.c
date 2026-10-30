extern unsigned int *gUnknown_03004E60;
extern unsigned int gUnknown_03004E34[];
extern unsigned char gUnknown_03004E10;

unsigned int sub_0800DF9C(unsigned int *arg0);
void *sub_08013538(int);
void sub_0800DFFC(void *, void *);

void sub_0801ABF0(unsigned int *arg0)
{
    unsigned int *p;

    gUnknown_03004E60 = p = (unsigned int *)sub_08013538(sub_0800DF9C(arg0));
    gUnknown_03004E34[3] = (unsigned int)p + 4;
    sub_0800DFFC(arg0, p);
    gUnknown_03004E10 &= 0xFA;
}
