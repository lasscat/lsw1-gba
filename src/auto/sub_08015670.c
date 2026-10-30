extern void sub_080156A4(void *);

void sub_08015670(void *arg)
{
    void *r4 = arg;
    sub_080156A4(r4);
    r4 = (void *)((char *)r4 + 0xbc);
    *(unsigned short *)r4 |= 1;
}
