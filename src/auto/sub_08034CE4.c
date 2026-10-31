void sub_08035F20(void *);

void sub_08034CE4(void *arg)
{
    unsigned char *p = (unsigned char *)arg;
    unsigned short *w;
    int v;

    sub_08035F20(*(void **)(p + 0x68));
    w = (unsigned short *)(*(unsigned char **)(p + 0x68) + 0xF2);
    v = *w | 0x100;
    *w = v;
    *(p + 0xE2) = 0x14;
    *(unsigned short *)(p + 0xBC) |= 0x20;
    if ((unsigned char)(*(*(unsigned char **)(p + 0x68) + 0xE0) - 0x45) <= 2)
        *(unsigned int *)(p + 0x40) += 0xFFF10000;
}
