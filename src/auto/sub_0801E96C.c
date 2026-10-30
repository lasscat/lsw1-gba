extern void sub_08004458(unsigned char, unsigned char);

void sub_0801E96C(unsigned char *r4)
{
    unsigned short *r1 = 0;
    if (r4[0xe1] == 1) {
        *(unsigned int *)(r4 + 0x58) |= 2;
        return;
    }
    r1 = (unsigned short *)(r4 + 0xec);
    if (*r1 == 0) {
        sub_08004458(r4[0xf4], r4[0xf5]);
    } else {
        *r1 -= 1;
        return;
    }
    *(unsigned int *)(r4 + 0x58) |= 2;
}
