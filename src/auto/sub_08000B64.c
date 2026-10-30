void sub_08000B64(void *arg0, int arg1)
{
    unsigned char *ptr = (unsigned char *)arg0 + arg1 * 12 + 0xC4;
    *ptr &= 0xFD;
}
