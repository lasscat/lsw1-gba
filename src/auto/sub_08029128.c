void sub_08029128(void *arg0)
{
    void *r2 = arg0;
    short r0 = *(short *)((char *)r2 + 0x12);
    if (r0 > 0xc7) goto L1;
    *(unsigned int *)((char *)r2 + 0x58) |= 1;
    return;
L1:
    {
        unsigned int r0v = *(unsigned int *)((char *)r2 + 0x58);
        unsigned int r1v = 2;
        r1v = 0 - r1v;
        r0v &= r1v;
        *(unsigned int *)((char *)r2 + 0x58) = r0v;
    }
}
