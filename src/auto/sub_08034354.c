void sub_08034354(void *arg)
{
    unsigned char *p = (unsigned char *)arg + 0xb3;
    int m = 0x11;
    m = -m;
    *p &= (unsigned char)m;
}
