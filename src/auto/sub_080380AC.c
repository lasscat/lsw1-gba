void sub_080380AC(unsigned char *a)
{
    unsigned char v = a[0xE1];
    int c;
    a[0x10E] = v;
    *(unsigned short *)(a + 0xF2) &= 0xEFFF;
    c = a[0xE1];
    switch (c) {
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 14:
        *(unsigned int *)(a + 0x58) |= 8;
        {
            unsigned char t = a[0x122];
            a[0x10F] = t;
        }
        {
            unsigned char t = a[0x121];
            a[0x110] = t;
        }
        break;
    }
}
