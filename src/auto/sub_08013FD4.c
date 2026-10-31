extern unsigned int *gUnknown_030036E0;
extern unsigned int *gUnknown_0300376C;
extern unsigned int *gUnknown_03003768;
extern unsigned int gUnknown_03003770;
extern unsigned int gUnknown_030036DC;
extern unsigned int gUnknown_030049F0;

unsigned int sub_0800DF9C(unsigned int *arg0);
void *sub_08013538(int);
void sub_0800DFFC(void *, void *);

void sub_08013FD4(unsigned int *arg0, unsigned int *arg1, unsigned int *arg2)
{
    unsigned int *p0;
    unsigned int *p1;
    unsigned int *p2;
    unsigned char *q;
    unsigned char *d;
    unsigned short a;
    unsigned short b;
    unsigned int size;
    size = sub_0800DF9C(arg2);
    gUnknown_030036E0 = p0 = (unsigned int *)sub_08013538(size);
    sub_0800DFFC(arg2, p0);
    size = sub_0800DF9C(arg0);
    gUnknown_0300376C = p1 = (unsigned int *)sub_08013538(size);
    sub_0800DFFC(arg0, p1);
    size = sub_0800DF9C(arg1);
    gUnknown_03003768 = p2 = (unsigned int *)sub_08013538(size);
    gUnknown_03003770 = (unsigned int)p2 + 4;
    sub_0800DFFC(arg1, p2);
    gUnknown_030036DC = *(unsigned short *)gUnknown_03003768;
    q = (unsigned char *)&gUnknown_030049F0;
    d = (unsigned char *)gUnknown_030036E0;
    a = (d[3] << 8) | d[2];
    *(unsigned short *)(q + 0x412) = a;
    b = (d[5] << 8) | d[4];
    *(unsigned short *)(q + 0x414) = b;
}
