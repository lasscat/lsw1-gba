void sub_0800EABC(int a, int b, int c, int d);
void *sub_0801D0AC(const char *a);
int sub_0800EE40(int a, int b, int c, int d, unsigned char **e, int f, int *g);

void sub_08023078(int a0)
{
    int max = 0x7FFFFFFF;
    int v = 2;
    unsigned char *p;

    sub_0800EABC(2, 9, 0, -1);
    p = sub_0801D0AC(0);
    while (*p != 0) {
        v = sub_0800EE40(v, 0x78, a0, 0xea, &p, 1, &max);
        a0 += 8;
    }
}
