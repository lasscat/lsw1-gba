void sub_08037FF8(void *r0)
{
    unsigned short *p = (unsigned short *)((unsigned char *)r0 + 0xf2);
    *p &= 0xEFFF;
}
