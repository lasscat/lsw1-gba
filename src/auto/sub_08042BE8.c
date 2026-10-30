void sub_08042BE8(void *r0)
{
    void *r2 = r0;
    unsigned short *r1;
    unsigned int v;
    r1 = (unsigned short *)((char *)r2 + 0xdc);
    if (*r1 == 0) {
        return;
    }
    (*r1)--;
    if (*r1 != 0) {
        return;
    }
    v = *(unsigned int *)((char *)r2 + 0x58);
    v |= 2;
    v &= ~1;
    *(unsigned int *)((char *)r2 + 0x58) = v;
}
