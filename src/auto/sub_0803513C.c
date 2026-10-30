void sub_08009B38(void);
void sub_080144F4(void *);

void sub_0803513C(void *arg)
{
    unsigned int *p = (unsigned int *)((char *)arg + 0x58);
    *p |= 4;
    *(unsigned int *)((char *)arg + 0xd4) |= 0x80;
    *p &= 0xFFFFBFFF;
    *(void **) ((char *)arg + 0x8c) = (void *)sub_08009B38;
    sub_080144F4(arg);
}
