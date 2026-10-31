void *sub_080137A0(void *dest, unsigned int value, unsigned int count)
{
    unsigned char *dst = dest;
    unsigned int k = 4 - ((unsigned int)dest & 3);
    unsigned int i;
    unsigned int words;
    unsigned int tail;
    unsigned int fill;

    if (k != 4) {
        if (count < k)
            k = count;
        i = 0;
        if (i < k) {
            unsigned char *p = dest;
            do {
                *p++ = value;
                i++;
            } while (i < k);
        }
        count -= i;
        dst = (unsigned char *)dest + i;
    }
    words = count >> 2;
    fill = (value << 8) | value;
    fill |= fill << 16;
    for (i = 0; i < words; i++)
        ((unsigned int *)dst)[i] = fill;
    dst += i * 4;
    tail = count & 3;
    i = 0;
    if (i < tail) {
        unsigned char *p = dst;
        do {
            *p++ = value;
            i++;
        } while (i < tail);
    }
    return dest;
}
