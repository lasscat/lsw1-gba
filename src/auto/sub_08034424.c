void sub_080144F4(void *);

void sub_08034424(void *arg)
{
    unsigned char *p = (unsigned char *)arg;
    p[0xb3] |= 0x10;
    sub_080144F4(arg);
}
