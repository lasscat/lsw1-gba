
int sub_080020A8(void *arg)
{
    int r1 = 0;
    unsigned char *p = (unsigned char *)arg + 0x5c;
    if (*p == 1) {
        r1 = 1;
    }
    return r1;
}
