void CpuSet(const void *src, void *dest, unsigned int count);

void sub_0801845C(void *src, unsigned short *data, unsigned int *unk)
{
    int n = *data++;
    int i = 0;
    if (i < n) {
        unsigned short *p = data;
        do {
            unsigned short v = *p++;
            void *s = (char *)src + (v << 5);
            unsigned int bits = (*unk << 28) >> 30;
            void *d = (void *)((bits << 14) + (i << 5) + 0x06000000);
            CpuSet(s, d, 0x10);
            i++;
        } while (i < n);
    }
}
