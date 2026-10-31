int sub_08005D6C(int x, unsigned char *a)
{
    int ret = 0;
    unsigned char *q = a + 2;
    int off;

    if (*a & 1) {
        off = 0x200;
    } else if (*a & 2) {
        off = 0x20;
    } else {
        off = 0;
    }
    q += off;
    if (*a & 0x10) {
        if (*a & 8) {
            ret = (int)q;
        }
    }
    return ret;
}
