void CpuSet(const void *src, void *dest, unsigned int count);
extern unsigned char gUnknown_03002C54[];

void sub_080057E4(int a, unsigned short b, unsigned short c, void *src)
{
    unsigned char *data = &gUnknown_03002C54[a * 100];
    if (data[0] & 0x80) {
        b *= 2;
        c *= 2;
    }
    CpuSet(src, (void *)(*(unsigned int *)(data + 16) + (b << 5)), c << 4);
}
