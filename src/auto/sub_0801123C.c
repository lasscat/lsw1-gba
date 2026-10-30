extern void *gUnknown_0300340C;

int sub_0801123C(void)
{
    unsigned int r1 = 0;
    unsigned int base = (unsigned int)gUnknown_0300340C;
    unsigned char v = *(unsigned char *)(base + 0xe0);
    v -= 0x2c;
    v = (unsigned char)v;
    if (v > 7) {
        /* do nothing */
    } else {
        r1 = 1;
    }
    return r1;
}
