void sub_0800E9B4(unsigned int a);
void sub_0800EABC(int a, int b, int c, int d);
void *sub_0801D0AC(const char *a);
int sub_0800ECF4(int a0, int a1, int a2, int a3, int a4, unsigned char **a5, int a6);
int sub_0800EE40(int a, int b, int c, int d, unsigned char **e, int f, int *g);

void sub_08027A6C(void)
{
    int max = 0x7FFFFFFF;
    int v;
    unsigned char *p;

    sub_0800E9B4(*(unsigned int *)0x0804EB08);
    sub_0800EABC(0, 9, 0, -1);
    p = sub_0801D0AC((const char *)0x34);
    v = sub_0800ECF4(0xC8, 0x42, 0xCD, 0x91, 0x78, &p, 0);
    p = sub_0801D0AC((const char *)0x37);
    v = sub_0800EE40(v, 0x4E, 0x109, 0x46, &p, 1, &max);
    p = sub_0801D0AC((const char *)0x38);
    sub_0800EE40(v, 0xA8, 0x109, 0x46, &p, 1, &max);
}
