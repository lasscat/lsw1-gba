struct P { int x, y; };
struct C { int xc, yc; };
int sub_0800148C(int a, struct P p, struct C c, int r)
{
    int res;
    if (a & 0x20000000) {
        if (p.y > r + c.yc) {
            if (p.x > r + c.xc)
                res = 3;
            else
                res = 0;
        } else if (p.y < c.yc - r) {
            if (p.x > r + c.xc)
                res = 2;
            else if (p.x < c.xc - r)
                res = 1;
            else
                res = 2;
        } else {
            if (p.x > r + c.xc)
                res = 3;
            else if (p.x < c.xc - r)
                res = 1;
            else
                res = 4;
        }
    } else {
        if (p.y > r + c.yc) {
            if (p.x > r + c.xc)
                res = 7;
            else if (p.x < c.xc - r)
                res = 1;
            else
                res = 0;
        } else if (p.y < c.yc - r) {
            if (p.x > r + c.xc)
                res = 5;
            else if (p.x < c.xc - r)
                res = 3;
            else
                res = 4;
        } else {
            if (p.x > r + c.xc)
                res = 6;
            else if (p.x < c.xc - r)
                res = 2;
            else
                res = 8;
        }
    }
    return res;
}
