void CpuSet(const void *src, void *dest, unsigned int count);

extern unsigned char gUnknown_03002C50[];

void sub_08007254(int idx)
{
    unsigned int mask = 2 << idx;
    unsigned int *flags = (unsigned int *)gUnknown_03002C50;
    if ((*flags & mask) == 0)
        return;
    *flags &= ~mask;
    {
        unsigned char *base = gUnknown_03002C50 + 4 + idx * 100;
        const void *src = (const void *)(*(unsigned int *)(base + 8));
        void *dest = (void *)(*(unsigned int *)(base + 12));
        CpuSet(src, dest, 0x400);
    }
}
