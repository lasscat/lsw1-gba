extern void CpuFastSet(void *src, void *dst, unsigned int mode);
extern void LZ77UnCompVram(const void *src, void *dst);
extern void RLUnCompVram(const void *src, void *dst);
extern void sub_03000330_veneer(const void *src, void *dst, int unk);

void sub_080072A4(unsigned char *info, void *src, int size, void *dst)
{
    int type = (int)(((unsigned int)info[0] << 25) >> 30);
    switch (type) {
    case 0:
        CpuFastSet(src, dst, size / 4 & 0x1FFFFF);
        break;
    case 1:
        RLUnCompVram(src, dst);
        break;
    case 2:
        LZ77UnCompVram(src, dst);
        break;
    case 3:
        sub_03000330_veneer(src, dst, 0);
        break;
    }
}
