extern unsigned int *gUnknown_03004E64;
extern unsigned int gUnknown_03004E34[];
extern unsigned int gUnknown_03004E74;
extern unsigned int gUnknown_030049F0;
extern unsigned char *gUnknown_03004E54;

unsigned int sub_0800DF9C(unsigned int *arg0);
void *sub_08013538(int);
void sub_0800DFFC(void *, void *);

void sub_0801A934(unsigned int *arg0)
{
    unsigned int *p;
    unsigned char *q;
    unsigned char *d;
    unsigned short a;
    unsigned short b;
    unsigned short c;

    gUnknown_03004E64 = p = (unsigned int *)sub_08013538(sub_0800DF9C(arg0));
    gUnknown_03004E34[4] = (unsigned int)p + 4;
    sub_0800DFFC(arg0, p);

    gUnknown_03004E74 = *gUnknown_03004E64++ << 5;

    q = (unsigned char *)&gUnknown_030049F0;
    d = gUnknown_03004E54;

    a = d[0] * 4;
    *(unsigned short *)(q + 0x32C) = a;
    b = d[2] * 4;
    *(unsigned short *)(q + 0x32E) = b;
    a = d[0];
    *(unsigned short *)(q + 0x330) = a;
    b = d[2];
    *(unsigned short *)(q + 0x332) = b;
    *(unsigned int *)(q + 0x28C) = *(unsigned short *)(q + 0x32C) << 3;
    *(unsigned int *)(q + 0x290) = *(unsigned short *)(q + 0x32E) << 3;
    *(unsigned short *)(q + 0x320) = a;
    c = (*(unsigned short *)(q + 0x332) << 1) * *(unsigned short *)(q + 0x330);
    *(unsigned short *)(q + 0x2AE) = c;
}
