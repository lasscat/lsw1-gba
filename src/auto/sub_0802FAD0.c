void sub_0802FAD0(void *arg0)
{
    unsigned char *p = (unsigned char *)arg0;
    unsigned short *r1 = (unsigned short *)(p + 0xdc);
    *r1 = *r1 - 1;
    if (*r1 == 0) {
        unsigned int val = *(unsigned int *)(p + 0x58);
        val |= 2;
        val &= ~1;
        *(unsigned int *)(p + 0x58) = val;
    }
}
