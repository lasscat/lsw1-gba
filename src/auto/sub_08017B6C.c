extern int gUnknown_03004980[];
void sub_08017B6C(unsigned char *dst, int n)
{
    int n2 = n;
    unsigned char *d2 = dst;
    unsigned char *src;
    int bit;
    int v;
    if (n2 == 0)
        return;
    while (n2 != 0) {
        src = (unsigned char *)gUnknown_03004980[15];
        bit = gUnknown_03004980[16];
        v = *src;
        *d2 = (v >> bit) & 1;
        bit++;
        gUnknown_03004980[16] = bit;
        if (bit > 7) {
            gUnknown_03004980[15] = (int)(src + 1);
            gUnknown_03004980[16] = 0;
        }
        d2++;
        n2--;
    }
}
