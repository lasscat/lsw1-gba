extern unsigned char gUnknown_080534EC[];
int sub_08017400(int a, int b);

int sub_0802F278(int x)
{
    unsigned char *p;
    unsigned int r;

    if (x == 0)
        return 0x13;
    p = &gUnknown_080534EC[x * 12];
    r = sub_08017400(0, 0x63);
    if (r > p[0xa])
        return 0x13;
    r = sub_08017400(0, 0x63);
    while (p[1] < r) {
        r -= p[1];
        p += 2;
    }
    return p[0];
}
