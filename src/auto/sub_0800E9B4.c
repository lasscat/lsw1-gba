extern unsigned int gUnknown_03003250;

void sub_0800E9B4(unsigned int a)
{
    unsigned int v1 = (((a << 19) >> 27) << 11) + ((unsigned int)0xC0 << 19);
    unsigned int v2 = (((a << 28) >> 30) << 14) + ((unsigned int)0xC0 << 19);
    unsigned int *r3 = &gUnknown_03003250;
    unsigned int b, c;

    r3[7] = v1;
    r3[8] = v1;
    r3[9] = v2;
    b = a << 24;
    c = b >> 31;
    c += 1;
    r3[10] = c << 5;
    r3[11] = b >> 31;
}
