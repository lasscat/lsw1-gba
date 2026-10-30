extern unsigned char gUnknown_0300477C[];

void sub_0801539C(int arg0)
{
    unsigned char *p = gUnknown_0300477C + arg0;
    unsigned char *q;
    unsigned char *r;
    unsigned char c;

    *p = 0;
    q = gUnknown_0300477C + 0x22;
    c = *q;
    if (arg0 != c - 1)
        return;
    if (c == 0)
        return;
    r = p;
    do {
        *q = *q - 1;
        if (*q == 0)
            break;
        r--;
    } while (*r == 0);
}
