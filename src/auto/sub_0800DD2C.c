extern unsigned int sub_08004A5C(unsigned char, unsigned char);

void sub_0800DD2C(void *arg)
{
    unsigned char a = ((unsigned char *)arg)[4];
    unsigned char b = ((unsigned char *)arg)[5];
    unsigned int *p = (unsigned int *)sub_08004A5C(a, b);
    if (((unsigned char *)arg)[6] != 0)
        *(unsigned int *)((unsigned char *)p + 0xD4) |= 0x20;
    else
        *(unsigned int *)((unsigned char *)p + 0xD4) &= ~0x20;
}
