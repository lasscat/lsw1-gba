int sub_08005C74(int a, void *b, unsigned short c);
int sub_08005EA4(int a, int b, unsigned short c, unsigned short d, int e, int f);

int sub_08005B3C(int a, void *b, unsigned short c, unsigned short d, int e, int f)
{
    unsigned short r5;
    unsigned short r7;
    int r4;
    
    r5 = (unsigned short)c;
    r7 = (unsigned short)d;
    r4 = sub_08005C74(a, b, r5);
    if (r4 != 0) {
        sub_08005EA4(a, r4, r5, r7, e, f);
    }
    return r4;
}
