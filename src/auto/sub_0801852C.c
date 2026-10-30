void LZ77UnCompVram(const void *, void *);

void sub_0801852C(const void *src, const unsigned char *hdr)
{
    unsigned int dest = ((hdr[1] & 0x1F) << 11);
    dest = dest + 0x06000000;
    LZ77UnCompVram(src, (void *)dest);
}
