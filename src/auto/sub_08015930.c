extern unsigned int gUnknown_030048A0[];

unsigned int sub_08015930(unsigned int a)
{
    unsigned char *r1;
    signed int r2 = 0;
    unsigned int r3 = 3;

    r1 = (unsigned char *)gUnknown_030048A0;
    do {
        if (*(unsigned int *)r1 == a) {
            if ((r3 & r1[6]) == 0) {
                return r2;
            }
        }
        r1 += 8;
        r2 += 1;
    } while (r2 <= 15);
    return 0xff;
}
