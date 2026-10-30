void sub_08034A34(void *arg)
{
    unsigned char *p = (unsigned char *)arg + 0xb3;
    int m = 0x11;
    m = -m;
    *p &= (unsigned char)m;
    p += 2;
    m = 0x0d;
    m = -m;
    *p &= (unsigned char)m;
    p += 10;
    *p = 0;
    *(unsigned int *)((unsigned char *)arg + 0x58) |= 0x20011;
}
