int sub_080131E4(int a, int b, int c, int d);
int sub_0801346C(int a, int b);
int sub_08012FAC(int a, int b, int c);

int sub_0801473C(int *p)
{
    int v;
    int t;
    int s;
    int dx;
    int dy;
    int r;

    v = sub_080131E4(p[13], p[14], p[5], p[6]);
    t = sub_0801346C(v, p[2]);
    if (t < 0)
        s = -sub_0801346C(v, p[2]);
    else
        s = sub_0801346C(v, p[2]);
    dx = p[13] - p[5];
    dy = p[14] - p[6];
    r = sub_08012FAC(p[9], p[10], p[22] & 0x20000000);
    p[9] = sub_0801346C(dx, s);
    p[10] = sub_0801346C(dy, s);
    return r;
}
