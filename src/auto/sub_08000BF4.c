void sub_08000D00(void *arg0, int arg1);

void sub_08000BF4(void *arg0, unsigned int arg1)
{
    void *r2 = arg0;
    unsigned int *p = (unsigned int *)((char *)r2 + 0x98);
    if (*p != arg1) {
        *p = arg1;
        *(unsigned int *)((char *)r2 + 0x58) |= 0x80;
    }
    sub_08000D00(r2, 0);
}
