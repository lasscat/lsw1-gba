void sub_08003F14(void *a, unsigned short b, unsigned short c)
{
    *(unsigned short *)((char *)a + 0x54) = b;
    *(unsigned short *)((char *)a + 0x56) = c;
}
