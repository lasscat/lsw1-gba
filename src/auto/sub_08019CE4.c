extern void sub_080125F8(void);

void sub_08019CE4(int a, unsigned short b)
{
    unsigned short i;

    *(volatile unsigned short *)0x04000050 = (unsigned short)(b | 0xC0);
    i = 0;
    do {
        *(volatile unsigned short *)0x04000054 = (unsigned short)(i >> 3);
        sub_080125F8();
        i++;
    } while (i <= 0x7F);
}
