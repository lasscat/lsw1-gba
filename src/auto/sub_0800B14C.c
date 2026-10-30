void sub_0801C404(int);

extern unsigned char gUnknown_03002BDC;
extern unsigned int gUnknown_03006B14;

void sub_0800B14C(void *p)
{
    if (gUnknown_03002BDC == 1) {
        gUnknown_03006B14 |= 0x01000000;
    }
    sub_0801C404(((unsigned char *)p)[4]);
}
