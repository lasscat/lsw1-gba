void sub_08000D58(void *a, int b, int c)
{
    *(int *)((char *)a + 0x34) = b;
    *(int *)((char *)a + 0x38) = c;
}
