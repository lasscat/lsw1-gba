void sub_08000E24(void *a, int b)
{
    void *p = a;
    unsigned char *q = (unsigned char *)p + 0xb3;
    if (((int)(*q) << 0x1a) < 0)
        b = -b;
    *(int *)((unsigned char *)p + 0x28) = b;
}
