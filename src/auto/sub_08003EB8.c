void sub_08003EB8(void *a, int b, int c)
{
    int r1;
    int r2;
    r1 = b << 8;
    *(unsigned short *)((char *)a + 0x4c) = (unsigned short)r1;
    r2 = c << 8;
    *(unsigned short *)((char *)a + 0x4e) = (unsigned short)r2;
}
