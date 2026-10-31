struct AY { int x; int y; };
struct XY { int y; int z; };
void sub_0801B574(int a, int b, int c, int d, int e);
void sub_0801A554(int a, int b, int c, int d);
void sub_0801BA64(int a0, struct AY ay, struct XY s)
{
    int t;
    int cur;
    if ((ay.y >> 3) == (s.z >> 3))
        return;
    if (ay.y > s.z) {
        cur = (((ay.y - s.z) >> 3) << 3) + s.z;
        if (cur < s.z)
            return;
        t = ay.y >> 3;
        do {
            if (t != (cur >> 3)) {
                int v = cur + 0xa8;
                sub_0801B574(s.y, cur, v, 0, a0);
                sub_0801A554(s.y, v, 1, a0);
            }
            cur -= 8;
        } while (cur >= s.z);
    } else {
        cur = s.z - (((s.z - ay.y) >> 3) << 3);
        if (cur > s.z)
            return;
        t = ay.y >> 3;
        do {
            if (t != (cur >> 3)) {
                sub_0801B574(s.y, cur + 0xa0, cur - 8, 0, a0);
                sub_0801A554(s.y, cur - 8, 1, a0);
            }
            cur += 8;
        } while (cur <= s.z);
    }
}
