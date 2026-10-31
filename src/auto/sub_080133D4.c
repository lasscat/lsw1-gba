struct P { int x; int y; };
extern int sub_080130D4(struct P p);
extern int gUnknown_0804BA04[];
struct P sub_080133D4(struct P p, struct P center, int e)
{
    struct P r;
    int angle;
    int t;
    r.x = p.x - center.x;
    r.y = p.y - center.y;
    angle = sub_080130D4(r);
    t = angle - 0x40;
    r.x = ((gUnknown_0804BA04[0xFF & ~t] << 8) >> 16) << 8;
    r.y = ((gUnknown_0804BA04[0xFF & ~angle] << 8) >> 16) << 8;
    r.x = center.x + e * r.x;
    r.y = center.y + e * r.y;
    return r;
}
