extern unsigned char gUnknown_03003764;
extern unsigned int gUnknown_030036E4[];

void sub_08014F08(unsigned int a)
{
    int i = 0;
    int n = gUnknown_03003764;
    unsigned int *base = gUnknown_030036E4;
    unsigned int *p;

    if (i < n) {
        p = base;
        do {
            if (*p++ == a)
                return;
            i++;
        } while (i < n);
    }
    gUnknown_030036E4[gUnknown_03003764] = a;
    gUnknown_03003764++;
}
