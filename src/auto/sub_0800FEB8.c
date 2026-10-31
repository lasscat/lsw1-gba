extern unsigned char gUnknown_030033EB;
extern unsigned char gUnknown_0300332C[];
extern void sub_0800FD8C(int arg0, int arg1);

int sub_0800FEB8(int arg0, int arg1)
{
    int delta = 1;
    unsigned char *p;
    unsigned char *q;
    int tmp;
    unsigned char val;

    if (arg1 != 0)
        delta -= 2;
    p = &gUnknown_030033EB;
    q = p + 1;
    do {
        tmp = *p + delta;
        *p = tmp;
        val = (unsigned char)tmp;
        if (val > 3) {
            if (arg1 != 0)
                *p = 3;
            else
                *p = arg1;
        }
        val = *(unsigned char *)((signed char)*p + (int)q);
    } while (val > 0x68);
    if (arg0 != 0)
        sub_0800FD8C(val, arg0);
    return (signed char)gUnknown_0300332C[0xBF];
}
