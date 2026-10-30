extern void sub_0800DFFC(void *, void *);

void sub_08018428(void *src, void *unk)
{
    unsigned int val = *(unsigned int *)unk;
    unsigned int bits = (val << 28) >> 30;
    void *dst = (void *)(0x06000000 + (bits << 14));
    sub_0800DFFC(src, dst);
}
