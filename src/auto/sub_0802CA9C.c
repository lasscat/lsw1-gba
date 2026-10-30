/* Sets bit "bit" of the byte at gUnknown_03006B1C[0x3CE + index] to "value".
   The compiler emits the clear-then-add sequence of the original code. */

extern unsigned char gUnknown_03006B1C[];

void sub_0802CA9C(int index, int bit, int value)
{
    unsigned char *base = (unsigned char *)gUnknown_03006B1C;
    unsigned int offset = 0x3CE;
    base = (unsigned char *)((unsigned int)base + offset);
    {
        unsigned char *entry = &base[index];
        unsigned int bits = 1 << bit;
        unsigned int current = *entry;
        current &= ~bits;
        bits = current;
        bits += ((unsigned int)value << bit);
        *entry = bits;
    }
}
