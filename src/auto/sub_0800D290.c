extern unsigned char gUnknown_0300332C[];
extern unsigned char gUnknown_03006B1C[];
extern unsigned int gUnknown_030036A4[];
extern unsigned int gUnknown_0300340C;
extern unsigned int sub_08042934(unsigned char);
extern void sub_08013DEC(unsigned int, unsigned int, unsigned int);

void sub_0800D290(void *arg)
{
    unsigned char *p = arg;
    unsigned int *q = (unsigned int *)&gUnknown_0300340C;
    if (*(short *)(*q + 0xD8) <= 0) {
        unsigned char *a = gUnknown_0300332C;
        if ((*(unsigned int *)(a + 0x8C) & 1) == 0)
            return;
    }
    gUnknown_03006B1C[0x293] = sub_08042934(p[4]);
    gUnknown_03006B1C[0x299] = p[5];
    {
        unsigned char *b = gUnknown_0300332C;
        int off = *(signed char *)(b + 0xBF);
        b += 0xC0;
        gUnknown_03006B1C[0x29D] = *(b + off);
    }
    sub_08013DEC(15, p[6], 0);
    gUnknown_030036A4[3] = gUnknown_03006B1C[0x293];
    *(unsigned int *)(*q + 0xD4) |= 0x1000000;
}
