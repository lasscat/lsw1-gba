extern int sub_08011850(const char *a, const char *b, int c);

void *sub_0801D0E8(const char *a, const char *b)
{
    const char *r4 = a;

    while (*r4 != 0)
        r4++;

    if (sub_08011850(b, r4, 0x400) == 0) {
        while (*r4 != 0)
            r4++;
        return (void *)r4;
    } else {
        return 0;
    }
}
