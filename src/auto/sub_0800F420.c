extern unsigned char gUnknown_030032D0[];

void sub_0801D174(void *, void *);

void sub_0800F420(void *arg0, int arg1)
{
    int r2 = arg1 * 15 * 2;
    void *r1 = (void *)(gUnknown_030032D0 + r2);
    sub_0801D174(arg0, r1);
}
