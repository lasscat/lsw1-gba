extern unsigned char gUnknown_03006824[];

void sub_0801E770(unsigned short a, unsigned short b)
{
    unsigned int end = a + b;
    unsigned int i = a;

    while (i < end) {
        unsigned int idx = i >> 3;
        unsigned int bit = i & 7;
        unsigned int mask;

        if (bit == 0 && end - i > 7) {
            mask = 0xff;
            i += 8;
        } else {
            mask = 1 << bit;
            i += 1;
        }
        gUnknown_03006824[idx] |= mask;
    }
}
