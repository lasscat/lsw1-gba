void sub_08035114(void *arg)
{
    unsigned int *p = (unsigned int *)((char *)arg + 0xd4);
    *p |= 0x80;
}
