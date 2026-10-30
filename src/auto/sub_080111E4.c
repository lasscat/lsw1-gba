extern unsigned char gUnknown_0300332C;

int sub_080111E4(int a)
{
    unsigned int i = 0;
    unsigned char *base = &gUnknown_0300332C;
    unsigned int v = 0;
    unsigned char *p2 = base + 0xC4;
    unsigned char *p1 = base + 0xC0;
    do {
        if (*p1 > 0x3C || *p2 != 0) {
            *p1 = a;
            *p2 = v;
            return i;
        }
        p2++;
        p1++;
        i++;
    } while (i <= 3);
    return -1;
}
