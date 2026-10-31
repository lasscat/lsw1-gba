struct S3250 {
    unsigned char pad[24];
    int v24;
};

extern struct S3250 gUnknown_03003250;

int sub_0800EE40(int a, int b, int c, int d, unsigned char **e, int f, int *g);

int sub_0800EDD8(int a0, int a1, int a2, int a3, unsigned char *a4, int a5)
{
    int max = 0x7FFFFFFF;

    while (*a4 != 0) {
        a0 = sub_0800EE40(a0, a1, a2, a3, &a4, a5, &max);
        a2 += gUnknown_03003250.v24;
    }
    return a0;
}
