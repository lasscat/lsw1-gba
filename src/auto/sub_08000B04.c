void sub_08000B04(void *arg0, int arg1, unsigned char arg2)
{
    unsigned char *ptr = (unsigned char *)arg0 + arg1 * 12 + 0xc6;
    *ptr = arg2;
}
