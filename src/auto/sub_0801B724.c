extern unsigned int gUnknown_030049F0[];
void sub_08007AA8(int *a, int b);
void sub_080079AC(int *a, int *b, unsigned int c, unsigned int d);
struct Pair { int x; int y; };
struct Pair sub_0801B724(void)
{
    struct Pair a;
    struct Pair b;
    struct Pair c;
    sub_08007AA8((int *)&a, 0);
    a.x -= 0x78;
    a.y -= 0x60;
    sub_080079AC((int *)&b, (int *)&c, gUnknown_030049F0[0xA3], gUnknown_030049F0[0xA4]);
    b.x += 1;
    b.y += 1;
    c.x -= 0xF1;
    c.y -= 0xA1;
    if (a.x < b.x)
        a.x = b.x;
    else if (a.x >= c.x)
        a.x = c.x;
    if (a.y < b.y)
        a.y = b.y;
    else if (a.y >= c.y)
        a.y = c.y;
    return a;
}
