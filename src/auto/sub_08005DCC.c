int sub_08009F40(int a, int b, int c);

int sub_08005DCC(unsigned char *a, int b, int c)
{
    unsigned char *p;
    int r5;
    unsigned char v2;
    int limit;
    int x;
    int bshift;

    p = a + 2;
    if (*a & 1) {
        r5 = 0x200;
        bshift = b << 4;
        limit = 0x10 - b;
        if ((unsigned int)c > (unsigned int)limit) {
            c = limit;
        }
        c = c << 4;
        sub_08009F40((int)p, bshift, c);
    } else if (*a & 2) {
        r5 = 0x20;
        v2 = a[1];
        x = (v2 >> 4) + b;
        x = x << 4;
        sub_08009F40((int)p, x, 0x10);
    } else {
        r5 = 0;
    }
    return r5;
}
