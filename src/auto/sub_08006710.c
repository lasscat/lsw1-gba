extern unsigned char gUnknown_03002C54[];

void sub_08006710(int a, int b, int c, int d, int e, int f, int g)
{
    unsigned char *p;
    unsigned short *src;
    unsigned short *dst;
    int i, j;

    p = gUnknown_03002C54 + a * 100;
    src = (unsigned short *)(*(unsigned int *)(p + 0xC) + (e << 6) + (d << 1));
    dst = (unsigned short *)(*(unsigned int *)(p + 0xC) + (g << 6) + (f << 1));

    for (i = c; i > 0; i--) {
        for (j = b; j > 0; j--) {
            *dst++ = *src++;
        }
        src += 32 - b;
        dst += 32 - b;
    }
}
