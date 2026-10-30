extern unsigned char gUnknown_03006B1C[];

int sub_08040C00(int a)
{
    unsigned int i;
    unsigned char *base;
    unsigned char *p;
    unsigned char v;

    i = 0;
    base = gUnknown_03006B1C;
    p = base + 0x1a;
    for (; i <= 6; i++) {
        v = *p;
        p += 0x58;
        if (v == a)
            return i;
    }
    return -1;
}
