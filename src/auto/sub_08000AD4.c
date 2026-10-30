void sub_08000AD4(void *arg0, int arg1, unsigned char arg2)
{
    unsigned char *p = (unsigned char *)arg0;
    int i = arg1;
    i = i * 3;
    i = i << 2;
    p = p + i;
    p = p + 0xc5;
    *p = arg2;
}
