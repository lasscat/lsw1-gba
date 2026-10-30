extern void sub_08036414(void *);

void sub_080365D8(void *arg)
{
    void *r4 = arg;
    sub_08036414(r4);
    *(unsigned char *)((unsigned char *)r4 + 0x11F) = 2;
}
