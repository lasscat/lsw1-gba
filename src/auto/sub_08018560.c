extern void RLUnCompVram(const void *src, void *dest);

void sub_08018560(const void *src, const void *a)
{
    unsigned char b = ((const unsigned char *)a)[1];
    void *dest = (void *)(((b & 0x1F) << 11) + 0x6000000);
    RLUnCompVram(src, dest);
}
