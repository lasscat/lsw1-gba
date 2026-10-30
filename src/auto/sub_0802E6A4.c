extern unsigned char gUnknown_0300332C[];

void sub_0802E6A4(void)
{
    unsigned char index = gUnknown_0300332C[0xB9];
    unsigned int k = index * 0x7C;
    unsigned char *q = gUnknown_0300332C + 0x10;
    unsigned int i = 0;
    unsigned char val = 0;
    unsigned char *p = (unsigned char *)(k + (unsigned int)q);

    do {
        *p++ = val;
        i++;
    } while (i <= 0x18);
}
