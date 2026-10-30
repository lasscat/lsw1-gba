struct S3250 {
    unsigned char pad[24];
    int v24;
};

extern struct S3250 gUnknown_03003250;

int sub_0800EE40(int a, int b, int c, int d, unsigned char **e, int f, int *g);

int sub_0800ECF4(int a0, int a1, int a2, int a3, int a4, unsigned char **a5, int a6)
{
    int max = 0x7FFFFFFF;
    int step;

    while (**a5 != 0 && a4 >= gUnknown_03003250.v24) {
        a0 = sub_0800EE40(a0, a1, a2, a3, a5, a6, &max);
        step = gUnknown_03003250.v24;
        a2 += step;
        a4 -= step;
    }
    return a0;
}
