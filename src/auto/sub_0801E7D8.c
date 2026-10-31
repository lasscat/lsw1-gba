extern unsigned char gUnknown_03006824[];

void sub_0801E7D8(unsigned short arg0, unsigned short arg1)
{
    unsigned int start = arg0;
    unsigned int end;
    unsigned int i;

    if (start == 0xFFFF)
        return;
    end = start + arg1;
    i = start;
    if (i >= end)
        return;
    do {
        unsigned int index = i >> 3;
        unsigned int bit = i & 7;
        unsigned int mask;

        if (bit == 0 && end - i > 7) {
            mask = 0xFF;
            i += 8;
        } else {
            mask = 1 << bit;
            i += 1;
        }
        gUnknown_03006824[index] &= ~mask;
    } while (i < end);
}
