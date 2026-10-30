void sub_0802A5BC(unsigned char *p, unsigned char a, unsigned char b, int c)
{
    p[0] = a;
    p[1] = b;
    if (c == 0) {
        p[2] = c;
        goto label;
    }
    p[2] = 0x1d;
label:
    p[3] = c;
}
