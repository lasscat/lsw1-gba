void sub_08033AF4(void *a)
{
    unsigned short *p = (unsigned short *)((unsigned char *)a + 0xdc);
    if (*p != 0) {
        *p = *p - 1;
    }
}
