extern unsigned int *gUnknown_03004E6C;
extern unsigned int gUnknown_03004E34[];
extern unsigned int gUnknown_03004E74[];
extern unsigned int gUnknown_030049F0;
extern unsigned char *gUnknown_03004E5C;

unsigned int sub_0800DF9C(unsigned int *arg0);
void *sub_08013538(int);
void sub_0800DFFC(void *, void *);

void sub_0801AB4C(unsigned int *arg0)
{
    unsigned int *p;
    unsigned char *q;
    unsigned char *d;
    unsigned short a;
    unsigned short b;
    unsigned short c;

    gUnknown_03004E6C = p = (unsigned int *)sub_08013538(sub_0800DF9C(arg0));
    gUnknown_03004E34[6] = (unsigned int)p + 4;
    sub_0800DFFC(arg0, p);

    gUnknown_03004E74[2] = *gUnknown_03004E6C++ << 5;

    q = (unsigned char *)&gUnknown_030049F0;
    d = gUnknown_03004E5C;

    a = d[0] * 4;
    *(unsigned short *)(q + 0x33C) = a;
    b = d[2] * 4;
    *(unsigned short *)(q + 0x33E) = b;
    a = d[0];
    *(unsigned short *)(q + 0x340) = a;
    b = d[2];
    *(unsigned short *)(q + 0x342) = b;
    *(unsigned short *)(q + 0x324) = a;
    c = (*(unsigned short *)(q + 0x342) << 1) * *(unsigned short *)(q + 0x340);
    *(unsigned short *)(q + 0x2B2) = c;
}
