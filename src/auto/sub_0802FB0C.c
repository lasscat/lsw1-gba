int sub_0802FB0C(void *arg0)
{
    unsigned char *p = (unsigned char *)arg0;
    int v = p[0x5f];
    if (v == 4) {
        int w = p[0xb3] << 27;
        v = 6;
        if (w >= 0)
            v = 2;
    } else if (v == 5) {
        v = 6;
    } else if (v == 3) {
        v = 2;
    }
    return v;
}
