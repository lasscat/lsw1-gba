extern void sub_0801DE20(void *);

int sub_0801D8D4(void *arg)
{
    unsigned char *p = (unsigned char *)arg + 0x35;
    unsigned char v = p[0];
    if (v != 0) {
        p[0] = v - 1;
        sub_0801DE20(arg);
        return 1;
    } else {
        return 0;
    }
}
