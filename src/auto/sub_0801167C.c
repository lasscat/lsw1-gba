void sub_080393C4(int, unsigned char);

void sub_0801167C(void *r0)
{
    void *r1;
    unsigned short r0;
    r1 = r0;
    r0 = *(unsigned short *)((char *)r1 + 0xdc);
    if (r0 > 0x14) {
        sub_080393C4((int)r1, 0x23);
        return;
    }
    if (r0 > 0xa) {
        sub_080393C4((int)r1, 0x22);
        return;
    }
}
