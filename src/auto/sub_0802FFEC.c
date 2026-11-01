extern unsigned char gUnknown_03006FB0[];

void sub_0802FFEC(void)
{
    unsigned char *p;
    unsigned int *state;

    gUnknown_03006FB0[4] = 1;
    p = *(unsigned char * volatile *)(gUnknown_03006FB0 + 8); // FAKE: preserve target pointer-field read
    if (p != 0) {
        state = (unsigned int *)(p + 0x58);
        *state |= 0x20000;
        p = *(unsigned char * volatile *)(gUnknown_03006FB0 + 8); // FAKE: preserve target pointer-field read
        state = (unsigned int *)(p + 0x58);
        *state &= ~1;
    }
}
