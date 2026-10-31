void LZ77UnCompVram(const void *, void *);
void CpuSet(const void *src, void *dest, unsigned int count);

void sub_080182D8(const void *src, const void *src2, const void *src3, unsigned int count, const void *hdr)
{
    unsigned int val = *(const unsigned int *)hdr;
    unsigned int bits = (val << 28) >> 30;
    void *dst = (void *)(0x06000000 + (bits << 14));
    LZ77UnCompVram(src, dst);
    CpuSet(src3, (void *)(0x06000000 + ((((const unsigned char *)hdr)[1] & 0x1F) << 11)), (count << 10) >> 11);
}
