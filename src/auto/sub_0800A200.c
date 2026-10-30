extern unsigned char gUnknown_03002EC4[];
unsigned int sub_0800A960(void);

unsigned int sub_0800A200(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int i = sub_0800A960();
    unsigned char *p = gUnknown_03002EC4 + (i << 3);
    unsigned int e = 0;
    p[0] = d;
    p[1] = c;
    p[2] = e;
    p[3] = a;
    p[4] = a;
    p[5] = a + b - 1;
    p[6] = b;
    p[7] = b;
    return i;
}
