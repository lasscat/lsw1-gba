void RLUnCompVram(const void *, void *);

void sub_08018378(const void *src, const void *src2, const void *hdr)
{
    unsigned int val = *(const unsigned int *)hdr;
    unsigned int bits = (val << 28) >> 30;
    void *dst = (void *)(0x06000000 + (bits << 14));
    RLUnCompVram(src, dst);
    RLUnCompVram(src2, (void *)(0x06000000 + ((((const unsigned char *)hdr)[1] & 0x1F) << 11)));
}
