extern void sub_080361AC(void *);

void sub_08036278(void *arg)
{
    void *r4 = arg;
    sub_080361AC(r4);
    *(unsigned short *)((unsigned char *)r4 + 0xF2) |= 0x40;
    if (*(unsigned char *)((unsigned char *)r4 + 0xE0) == 0x5E)
        *(unsigned char *)((unsigned char *)r4 + 0xE1) = 0x21;
}
