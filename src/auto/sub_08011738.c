extern unsigned char gUnknown_0300332C[];

int sub_08011738(void)
{
    unsigned int count = 0;
    unsigned int i = 0;
    unsigned char *base = gUnknown_0300332C;
    unsigned int *p = (unsigned int *)(base + 0x7c);

    do {
        if (*p++ != 0)
            count++;
        i++;
    } while (i <= 2);
    return 3 - count;
}
