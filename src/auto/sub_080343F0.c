void sub_080144F4(void *);

void sub_080343F0(void *r0)
{
    unsigned char *p = (unsigned char *)r0 + 0xb3;
    unsigned int mask = 0x11;
    mask = -mask;
    *p = (unsigned char)(*p & mask);
    sub_080144F4(r0);
}
