void sub_08011AD4(unsigned int a, unsigned short *b, int c, unsigned char *d)
{
    int e = 0x100;
    int n = c >> 1;
    unsigned int bit = a & 15;
    int bits = 15 - bit;
    unsigned int off = (a >> 3) & ~1u;
    unsigned short *p = (unsigned short *)(off + 0x8000000);
    unsigned int w = *p;
    unsigned char *t3;
    unsigned char *t2;

    p = (unsigned short *)(off + 0x8000002);
    w >>= bit;
    if (n <= 0)
        return;
    t2 = d + 18;
    t3 = d + 36;
    do {
        int len = 0;
        int val = 0;
        unsigned char *tp = d;

        do {
            int k;
            val <<= 1;
            val += w & 1;
            k = *tp++;
            if (--bits == -1) {
                w = *p++;
                bits = 15;
            } else {
                w >>= 1;
            }
            if (val < k)
                break;
            val -= k;
            len++;
        } while (1);
        {
            int s = t2[len] + val;
            s = t3[s];
            if (e != 0x100) {
                *b++ = e + (s << 8);
                n--;
                e = 0x100;
            } else {
                e = s;
            }
        }
    } while (n > 0);
}
