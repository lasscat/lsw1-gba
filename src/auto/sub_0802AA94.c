extern unsigned int gUnknown_0300332C;

void *sub_0802AA94(void)
{
    unsigned int *p = &gUnknown_0300332C;
    *(volatile unsigned char *)((unsigned char *)p + 0xb8);
    return (void *)*p;
}
