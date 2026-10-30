extern unsigned int sub_08004A5C(unsigned char, unsigned char);

void sub_0800CF40(unsigned char *a)
{
    unsigned int r = sub_08004A5C(a[4], a[5]);
    unsigned char *p;
    int m;
    unsigned int t;
    if (r == 0)
        return;
    p = (unsigned char *)r;
    m = 13;
    p += 181;
    t = (a[6] & 3) << 2;
    p[0] = (p[0] & -m) | t;
}
