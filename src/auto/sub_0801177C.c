extern unsigned char gUnknown_0300332C[];

void sub_0801177C(unsigned int val)
{
    unsigned int *slot;
    unsigned int i;
    unsigned int v;
    unsigned char *base;
    v = val;
    i = 0;
    base = gUnknown_0300332C;
    slot = (unsigned int *)(base + 0x7c);
    do {
        if (*slot == 0) {
            *slot = v;
            break;
        }
        slot++;
        i++;
    } while (i <= 2);
}
