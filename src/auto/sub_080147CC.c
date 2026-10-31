int sub_08014B90(int a, int *p);

int sub_080147CC(int *p)
{
    unsigned int v = ((unsigned char *)p)[0x5f];
    int flags = p[22];
    int r;
    int t;

    if (flags & 0x20000000)
        v <<= 1;
    else if (flags & 0x40000000)
        v >>= 1;
    else if (flags < 0)
        v = ((v + 0x10) & 0xFF) >> 5;
    if (v & 1) {
        r = sub_08014B90(v & 0xFE, p);
        t = sub_08014B90((v + 1) & 7, p);
        if (r == 0)
            r = t;
    } else {
        r = sub_08014B90(v, p);
        v = (v + 2) & 7;
        t = sub_08014B90(v, p);
        if (r == 0)
            r = t;
        t = sub_08014B90((v + 4) & 7, p);
        if (r == 0)
            r = t;
        if (r != 0)
            p[53] |= 0x60000;
    }
    return r;
}
