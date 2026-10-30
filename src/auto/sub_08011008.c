extern unsigned char gUnknown_0300332C[];

unsigned int sub_08011008(unsigned int arg0)
{
    unsigned int i = 0;
    unsigned int addr = (unsigned int)gUnknown_0300332C;
    unsigned char *p = (unsigned char *)(addr + 0xC0);

    do {
        if (*p++ != arg0) {
            i++;
        } else {
            return 1;
        }
    } while (i <= 3);
    return 0;
}
