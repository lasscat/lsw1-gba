extern unsigned int gUnknown_03003250[];

void sub_0800F5B0(unsigned char *p)
{
    int i, j;
    unsigned char *q;
    if (gUnknown_03003250[11] == 1) {
        for (i = 8; i > 0; i--) {
            q = p + 7;
            for (j = 4; j > 0; j--) {
                unsigned char t = *p;
                *p = *q;
                *q = t;
                p++;
                q--;
            }
            p += 4;
        }
    } else {
        for (i = 8; i > 0; i--) {
            q = p + 3;
            for (j = 2; j > 0; j--) {
                unsigned char a = (*p >> 4) | (*p << 4);
                unsigned char b = (*q >> 4) | (*q << 4);
                *p = b;
                *q = a;
                p++;
                q--;
            }
            p += 2;
        }
    }
}
