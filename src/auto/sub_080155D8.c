extern unsigned int gUnknown_030048A0;

void sub_080155D8(void)
{
    unsigned int zero = 0;
    unsigned char *p = (unsigned char *)&gUnknown_030048A0;
    int i = 15;
    do {
        *(unsigned int *)p = zero;
        *(unsigned short *)(p + 4) = zero;
        *(unsigned char *)(p + 6) = zero;
        p += 8;
        i--;
    } while (i >= 0);
}
