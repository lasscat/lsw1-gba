void sub_08034380(void *arg)
{
    unsigned char *p = (unsigned char *)arg;
    unsigned char *q = p + 0xb1;
    unsigned char *r;
    int m;
    int n;
    int v;
    int z;
    m = 0xd;
    m = -m;
    *q &= m;
    n = 0x21;
    n = -n;
    *q &= n;
    p[0xb5] &= m;
    r = p + 0xbf;
    z = 0;
    v = 3;
    *r = v;
    p[0xb3] &= v - 0x14;
    *(unsigned int *)(p + 0x58) = 0x20001;
    *(unsigned int *)(p + 0xc) = 0xa0000;
    *(unsigned int *)(p + 0x10) = 0xa0000;
    *(unsigned int *)(p + 0x40) = z;
}
