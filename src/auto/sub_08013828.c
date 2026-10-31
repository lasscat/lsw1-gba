void *sub_08013828(void *dst, void *src, unsigned int n)
{
    unsigned int i;
    if ((((unsigned int)dst & 3) != 0) || (((unsigned int)src & 3) != 0)) {
        char *d;
        char *s;
        char c;
        i = 0;
        if (i < n) {
            d = (char *)dst;
            s = (char *)src;
            do {
                c = *s;
                s++;
                *d = c;
                d++;
                i++;
            } while (i < n);
        }
    } else {
        unsigned int words;
        unsigned int *wd;
        unsigned int *ws;
        unsigned int rem;
        char *rd;
        char *rs;
        char c;
        words = n >> 2;
        i = 0;
        if (i < words) {
            wd = (unsigned int *)dst;
            ws = (unsigned int *)src;
            do {
                *wd++ = *ws++;
                i++;
            } while (i < words);
        }
        rem = n & 3;
        i = n - rem;
        if (rem-- > 0) {
            rd = (char *)(i + (unsigned int)dst);
            rs = (char *)(i + (unsigned int)src);
            do {
                c = *rs;
                rs++;
                *rd = c;
                rd++;
            } while (rem-- > 0);
        }
    }
    return dst;
}
