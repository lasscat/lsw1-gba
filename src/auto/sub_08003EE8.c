void sub_08003EE8(void *a, unsigned short b, unsigned short c)
{
    *(unsigned short *)((unsigned char *)a + 0x50) = b;
    *(unsigned short *)((unsigned char *)a + 0x52) = c;
}
