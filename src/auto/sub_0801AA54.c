extern unsigned int *gUnknown_03004E68;
extern unsigned int gUnknown_03004E34[];
extern unsigned int gUnknown_03004E74[];
extern unsigned int gUnknown_030049F0;
extern unsigned char *gUnknown_03004E58;

unsigned int sub_0800DF9C(unsigned int *arg0);
void *sub_08013538(int);
void sub_0800DFFC(void *, void *);

void sub_0801AA54(unsigned int *arg0)
{
    unsigned int *p;
    unsigned char *q;
    unsigned char *d;
    unsigned short a;
    unsigned short b;
    unsigned short c;

    gUnknown_03004E68 = p = (unsigned int *)sub_08013538(sub_0800DF9C(arg0));
    gUnknown_03004E34[5] = (unsigned int)p + 4;
    sub_0800DFFC(arg0, p);

    gUnknown_03004E74[1] = *gUnknown_03004E68++ << 5;

    q = (unsigned char *)&gUnknown_030049F0;
    d = gUnknown_03004E58;

    a = d[0] * 4;
    *(unsigned short *)(q + 0x334) = a;
    b = d[2] * 4;
    *(unsigned short *)(q + 0x336) = b;
    a = d[0];
    *(unsigned short *)(q + 0x338) = a;
    b = d[2];
    *(unsigned short *)(q + 0x33A) = b;
    *(unsigned short *)(q + 0x322) = a;
    c = (*(unsigned short *)(q + 0x33A) << 1) * *(unsigned short *)(q + 0x338);
    *(unsigned short *)(q + 0x2B0) = c;
}
