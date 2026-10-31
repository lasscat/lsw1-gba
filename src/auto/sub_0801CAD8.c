struct P {
    int x;
    int y;
};
extern int sub_080130D4(struct P p);
extern int sub_08013254(struct P, int, int);
extern int sub_0801BFB8(int, int, int);
extern int gUnknown_03002E14[];
int sub_0801CAD8(struct P pos, int arg2, int arg3)
{
    int *p = gUnknown_03002E14;
    struct P d;
    int angle;
    int dist;
    int v1;
    int v2;
    int prod;
    d.x = p[0] - pos.x;
    d.y = p[1] - pos.y;
    angle = sub_080130D4(d);
    dist = sub_08013254(pos, p[0], p[1]);
    dist >>= 18;
    v1 = 0x44 - dist;
    if (v1 > 0x7f)
        v1 = 0x7f;
    if (v1 <= 0x13 && arg3 != 0)
        return 0;
    if (v1 <= 9)
        v1 = 10;
    v2 = angle - 0x40;
    if (v2 < 0)
        v2 = angle + 0xc0;
    if (v2 > 0x80)
        v2 -= 0x100;
    if (dist <= 0x1f) {
        prod = v2 * dist;
        if (prod < 0)
            prod += 0x1f;
        v2 = prod >> 5;
    }
    if (v2 < -0x3c)
        v2 = -0x3c;
    if (v2 > 0x3c)
        v2 = 0x3c;
    return sub_0801BFB8(arg2, v1, v2);
}
