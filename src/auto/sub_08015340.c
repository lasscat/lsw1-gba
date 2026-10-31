extern unsigned char gUnknown_0300477C[];

int sub_08015340(void)
{
    unsigned short i = 0;
    unsigned short n = 0x20;
    while (1) {
        if (gUnknown_0300477C[i] != 1) {
            gUnknown_0300477C[i] = 1;
            if (i >= gUnknown_0300477C[0x22])
                gUnknown_0300477C[0x22]++;
            break;
        }
        i++;
        n--;
        if (n == 0)
            break;
    }
    return i;
}
