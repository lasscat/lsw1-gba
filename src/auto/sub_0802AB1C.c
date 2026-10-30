void sub_0802AB1C(void *a0, unsigned int a1)
{
    unsigned char *r2 = a0;
    unsigned int r3 = 0x116;
    unsigned char *r0 = (unsigned char *)(r2 + r3);
    r3 = ((unsigned int)(*r0) * a1) >> 8;
    r2 += 0x115;
    *(unsigned char *)r2 = (unsigned char)r3;
}
