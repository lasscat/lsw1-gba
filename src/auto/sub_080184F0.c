void CpuSet(const void *src, void *dest, unsigned int count);

void sub_080184F0(void *dest, void *src, const unsigned char *data)
{
    unsigned int r3 = (unsigned int)src;
    unsigned int r1 = data[1] & 0x1F;
    r1 = (r1 << 11);
    r1 = r1 + ((unsigned int)0xC0 << 19);
    r3 = (r3 << 10);
    r3 = r3 >> 11;
    CpuSet(dest, (void *)r1, r3);
}
