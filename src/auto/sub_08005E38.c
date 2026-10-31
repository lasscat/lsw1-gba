int sub_08009F40(int a, int b, int c);

int sub_08005E38(unsigned char *a, int b)
{
    int r;
    unsigned char *p;

    p = a + 2;
    if (*a & 1) {
        r = 0x200;
        sub_08009F40((int)(p + (b << 5)), b << 4, 0x100 - (b << 4));
    } else if (*a & 2) {
        r = 0x20;
        sub_08009F40((int)(p + (b << 4)), ((a[1] >> 4) + b) << 4, 0x10);
    } else {
        r = 0;
    }
    return r;
}
