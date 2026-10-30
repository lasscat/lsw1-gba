int sub_08005B90(int a, void *b, unsigned short c, unsigned short d);
int sub_08005EA4(int a, int b, unsigned short c, unsigned short d, int e, int f);

int sub_08005AE8(int a, void *b, unsigned short c, unsigned short d, int e, int f)
{
    unsigned short r5;
    unsigned short r7;
    int r4;

    r5 = (unsigned short)c;
    r7 = (unsigned short)d;
    r4 = sub_08005B90(a, b, r5, r7);
    if (r4 != 0) {
        sub_08005EA4(a, r4, r5, r7, e, f);
    }
    return r4;
}
