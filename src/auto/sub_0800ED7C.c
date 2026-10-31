struct S3250 {
    unsigned char pad[24];
    int v24;
};

extern struct S3250 gUnknown_03003250;

int sub_0800EE40(int a, int b, int c, int d, unsigned char **e, int f, int *g);

int sub_0800ED7C(int a, int b, int c, int d, int e, unsigned char **f, int g, int h)
{
    if (**f != 0 && e >= gUnknown_03003250.v24)
        a = sub_0800EE40(a, b, c, d, f, g, h);
    return a;
}
