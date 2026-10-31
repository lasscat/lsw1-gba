void sub_0803792C(unsigned char *p)
{
    unsigned int a;
    unsigned int b;

    p[0x10c]--;
    if (p[0x10c] != 0) {
        if ((p[0xe3] & 0x20) == 0)
            return;
    }
    a = p[0x5f];
    b = p[0x10d];
    if (a != b) {
        p[0xe3] |= 0x10;
        p[0x10d] = a;
    }
    if ((unsigned char)(p[0xe0] - 0x45) <= 2 && (((a + 8) & 0xff) >> 4) != (((b + 8) & 0xff) >> 4))
        p[0xe3] |= 4;
    else if ((((a + 0x10) & 0xff) >> 5) != (((b + 0x10) & 0xff) >> 5))
        p[0xe3] |= 4;
    p[0x10c] = 3;
}
