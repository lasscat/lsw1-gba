void sub_08001E64(void *arg0)
{
    void *r3 = *(void **)((unsigned char *)arg0 + 0x6c);
    *(int *)((unsigned char *)arg0 + 0xc) += *(int *)((unsigned char *)r3 + 0x24);
    *(int *)((unsigned char *)arg0 + 0x10) += *(int *)((unsigned char *)r3 + 0x28);
}
