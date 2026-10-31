void *memcpy(void *, const void *, unsigned int);
unsigned short sub_08005290(unsigned short x);

unsigned char *sub_08005230(unsigned char *a, unsigned char *b, unsigned char c)
{
    unsigned int ofs;
    unsigned char *p;
    unsigned char *src;
    unsigned short len;
    unsigned int n;

    ofs = c * 2;
    p = a + 2;
    src = a + *(unsigned short *)(p + ofs);
    len = ((unsigned short *)src)[2];
    ((unsigned short *)b)[2] = len;
    ((unsigned short *)b)[0] = ((unsigned short *)src)[0];
    ((unsigned short *)b)[1] = ((unsigned short *)src)[1];
    n = len * 2;
    memcpy(b + 8, src + 8, n);
    return b + sub_08005290(len + 4);
}
