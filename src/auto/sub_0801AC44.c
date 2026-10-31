extern unsigned int *gUnknown_03004E70;
extern unsigned int gUnknown_03004E34[];
extern unsigned int gUnknown_03004E74[];
extern unsigned int gUnknown_030049F0;
extern unsigned char *gUnknown_03004E60;

unsigned int sub_0800DF9C(unsigned int *arg0);
void *sub_08013538(int);
void sub_0800DFFC(void *, void *);

void sub_0801AC44(unsigned int *arg0)
{
    unsigned int *p;
    unsigned char *q;
    unsigned char *d;
    unsigned short a;
    unsigned short b;
    unsigned short c;

    gUnknown_03004E70 = p = (unsigned int *)sub_08013538(sub_0800DF9C(arg0));
    gUnknown_03004E34[7] = (unsigned int)p + 4;
    sub_0800DFFC(arg0, p);

    gUnknown_03004E74[3] = *gUnknown_03004E70++ << 5;

    q = (unsigned char *)&gUnknown_030049F0;
    d = gUnknown_03004E60;

    a = d[0] * 4;
    *(unsigned short *)(q + 0x344) = a;
    b = d[2] * 4;
    *(unsigned short *)(q + 0x346) = b;
    a = d[0];
    *(unsigned short *)(q + 0x348) = a;
    b = d[2];
    *(unsigned short *)(q + 0x34A) = b;
    *(unsigned short *)(q + 0x326) = a;
    c = (*(unsigned short *)(q + 0x34A) << 1) * *(unsigned short *)(q + 0x348);
    *(unsigned short *)(q + 0x2B4) = c;
}
