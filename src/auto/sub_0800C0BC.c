int sub_08018670(int a, int b);

void sub_0800C0BC(unsigned char *p)
{
    int v;

    v = (p[5] << 1) | p[4];
    v |= p[6] << 2;
    v |= p[7] << 3;
    sub_08018670((unsigned char)v, 0x1b);
}
