extern void (*gUnknown_08056FE8[])(unsigned char *);

void sub_080378D4(unsigned char *p)
{
    void (*f)(unsigned char *);

    if ((p[0xe3] & 0x12) != 0) {
        f = gUnknown_08056FE8[p[0xe2]];
        if (f != 0)
            f(p);
    }
    p[0xe3] = 0;
}
