extern unsigned char gUnknown_030068A4[];

void sub_0801E84C(unsigned short a, unsigned short b)
{
    unsigned int end;
    unsigned int i;
    unsigned int idx;
    unsigned int bit;
    unsigned int mask;
    if (a == 0xFFFF)
        return;
    end = a + b;
    i = a;
    while (i < end) {
        idx = i >> 3;
        bit = i & 7;
        if (bit == 0 && end - i > 7) {
            mask = 0xFF;
            i += 8;
        } else {
            mask = 1 << bit;
            i++;
        }
        gUnknown_030068A4[idx] &= ~mask;
    }
}
