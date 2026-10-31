struct P { int x; int y; };
extern int sub_080130D4(struct P p);
extern void sub_08047410(void *, int);
extern void sub_08047414(void *, int, int);
extern int sub_08013254(struct P, int, int);
extern int gUnknown_03002E14[];
int sub_0801CB9C(struct P p, void *obj)
{
    struct P d; int angle; int dist; int r2; int v1; int v2;
    d.x = gUnknown_03002E14[0] - p.x;
    d.y = gUnknown_03002E14[1] - p.y;
    angle = sub_080130D4(d);
    dist = sub_08013254(p, gUnknown_03002E14[0], gUnknown_03002E14[1]);
    r2 = (dist >> 18) + (dist >> 20);
    v1 = 0x44 - r2;
    if (v1 > 0x7f) v1 = 0x7f;
    if (v1 < 0) v1 = 0;
    v2 = angle - 0x20;
    if (v2 < 0) v2 = angle + 0xe0;
    if (v2 > 0x80) v2 -= 0x100;
    if (v2 > 0x40) v2 = 0x80 - v2;
    if (v2 < -0x40) v2 = -0x80 - v2;
    if (r2 <= 0x1f) v2 = (v2 * r2) / 32;
    if (v2 < -0x3c) v2 = -0x3c;
    if (v2 > 0x3c) v2 = 0x3c;
    sub_08047414(obj, v2, r2);
    sub_08047410(obj, v1);
    return dist;
}
