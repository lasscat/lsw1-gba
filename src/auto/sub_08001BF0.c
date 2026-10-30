void sub_08001BF0(void *arg0, unsigned char arg1)
{
    unsigned short *p = (unsigned short *)((unsigned char *)arg0 + 0xbc);
    *p |= 1;
    ((unsigned char *)arg0)[0xbe] = arg1;
}
