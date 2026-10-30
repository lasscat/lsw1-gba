void sub_080058B4(unsigned short *a, int b, int c, int d, int e, unsigned short f)
{
    int i;
    for (i = 0; i < e; i++) {
        unsigned short *p = (unsigned short *)((char *)a + ((c + i) << 6) + (b << 1));
        if (d > 0) {
            int n = d;
            do {
                *p++ = f;
                n--;
            } while (n != 0);
        }
    }
}
