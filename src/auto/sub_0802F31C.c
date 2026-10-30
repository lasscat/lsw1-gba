extern int sub_0802F278(int arg);

void sub_0802F31C(unsigned char *p)
{
    if (p[0x101] != 0) {
        int v = sub_0802F278(p[0x101]);
        if (v != 0x13)
            p[0x100] = (unsigned char)v;
    }
}
