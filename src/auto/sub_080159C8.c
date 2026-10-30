extern unsigned int gUnknown_030048A0[];

unsigned int sub_080159C8(void)
{
    unsigned char *r1;
    signed int r2 = 0;
    unsigned int r3 = 2;

    r1 = (unsigned char *)gUnknown_030048A0;
    do {
        if (*(unsigned short *)(r1 + 4) == 0) {
            if ((r3 & r1[6]) == 0) {
                return r2;
            }
        }
        r1 += 8;
        r2 += 1;
    } while (r2 <= 15);
    return 0xff;
}
