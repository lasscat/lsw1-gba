void sub_08000B34(void *arg0, int arg1)
{
    unsigned char *ptr;

    ptr = (unsigned char *)arg0 + arg1 * 12 + 0xC4;
    *ptr |= 2;
}
