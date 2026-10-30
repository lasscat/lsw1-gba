int sub_080152E4(const void *arg0)
{
    unsigned short v = *(const unsigned short *)((const char *)arg0 + 2);
    return (v >> 9) & 0x1F;
}
