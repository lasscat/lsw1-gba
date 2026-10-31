struct Pair40 {
    int f0;
    int f4;
};
extern struct Pair40 gUnknown_08047DCC[];

void sub_08034D4C(void *arg)
{
    unsigned char *p = (unsigned char *)arg;
    unsigned int idx = *(*(unsigned char **)(p + 0x68) + 0x5F);
    unsigned short *w;
    unsigned int zero;

    *(unsigned int *)(p + 0xC) += gUnknown_08047DCC[idx].f0 * 40;
    *(unsigned int *)(p + 0x10) += gUnknown_08047DCC[idx].f4 * 40;
    w = (unsigned short *)(p + 0xDC);
    zero = 0;
    *w = 5;
    *(unsigned int *)(p + 0x68) = zero;
    *(p + 0xE2) = 0x14;
    *(unsigned short *)(p + 0xBC) |= 0x20;
}
