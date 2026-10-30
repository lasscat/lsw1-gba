void sub_08000B94(void *arg0, int arg1)
{
    unsigned char *ptr = (unsigned char *)arg0 + arg1 * 3 * 4 + 0xc4;
    *ptr |= 4;
}
