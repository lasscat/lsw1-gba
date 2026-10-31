extern void sub_08004458(unsigned char a, unsigned char b);

void sub_08043AE4(unsigned char *a)
{
    sub_08004458(a[0xF9], a[0xF8]);
    {
        unsigned char *d = a;
        int *b = (int *)(d + 0xF0);
        if (*b != 0) {
            int t;
            d[0xE2] = 0x14;
            t = *b;
            *(unsigned short *)(d + 0xDC) = t;
        } else {
            d[0xE2] = 9;
        }
    }
}
