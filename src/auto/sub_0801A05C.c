extern void sub_080188B8(void);

void sub_0801A05C(unsigned short a)
{
    unsigned short i;

    *(volatile unsigned short *)0x04000050 = (unsigned short)(a | 0xC0);
    i = 0;
    do {
        *(volatile unsigned short *)0x04000054 = i;
        sub_080188B8();
        i++;
    } while (i <= 15);
    *(volatile unsigned short *)0x04000000 &= 0x9FFF;
}
