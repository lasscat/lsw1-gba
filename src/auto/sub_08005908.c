extern unsigned char gUnknown_03002C54[];

void sub_0800594C(int a, int b, int c, int d, int e, int f);

void sub_08005908(int a, int b, int c, int d, int e, unsigned short f)
{
    unsigned char *p = gUnknown_03002C54 + a * 100;
    int v = *(int *)(p + 12);
    sub_0800594C(v, b, c, d, e, f);
}
