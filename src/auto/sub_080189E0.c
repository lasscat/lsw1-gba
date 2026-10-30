extern void sub_080188B8(void);

void sub_080189E0(unsigned short r0)
{
    unsigned int r1;
    unsigned int r2;
    signed int r4;
    unsigned int r5;
    
    r0 = (r0 << 16) >> 16;
    r2 = 0x04000050;
    r1 = 0x80;
    r0 = r0 | r1;
    *(volatile unsigned short *)r2 = r0;
    r4 = 0;
    r5 = 0x04000054;
    do {
        *(volatile unsigned short *)r5 = r4;
        sub_080188B8();
        r4 += 2;
    } while (r4 <= 0x10);
}
