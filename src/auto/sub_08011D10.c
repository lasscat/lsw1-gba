extern unsigned short gUnknown_03003430[];

void sub_08011D10(void)
{
    unsigned short *p = gUnknown_03003430;
    unsigned short *q;
    int i;
    unsigned short v;
    p[4] = 1;
    v = 1;
    i = 0;
    q = p + 9;
    do {
        *q = v;
        q--;
        i--;
    } while (i >= 0);
}
