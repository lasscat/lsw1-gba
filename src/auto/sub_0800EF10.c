int sub_0800EB7C(unsigned char *p);
int sub_0800EBF0(unsigned char *p);
int sub_0800EF98(int a0, int a1, int a2, unsigned char *a3);

int sub_0800EF10(int a0, int a1, int a2, unsigned char *a3, int flags)
{
    int u = a1;
    int v = a2;
    if (flags == 1)
        u -= (sub_0800EB7C(a3) + 1) / 2;
    else if (flags == 2)
        u -= sub_0800EB7C(a3);
    if (flags == 4)
        v = a2 - (sub_0800EBF0(a3) + 1) / 2;
    else if (flags == 8)
        v = a2 - sub_0800EBF0(a3);
    return sub_0800EF98(a0, u, v, a3);
}
