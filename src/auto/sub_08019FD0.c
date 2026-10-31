extern void sub_080188B8(void);

void sub_08019FD0(unsigned short a)
{
    int i;

    *(volatile unsigned short *)0x04000048 = 0;
    *(volatile unsigned short *)0x0400004A = 0x1F;
    *(volatile unsigned short *)0x04000040 = 0xF0;
    *(volatile unsigned short *)0x04000044 = 0x20;
    *(volatile unsigned short *)0x04000042 = 0xF0;
    *(volatile unsigned short *)0x04000046 = 0x80A0;
    *(volatile unsigned short *)0x04000000 |= 0x6000;
    *(volatile unsigned short *)0x04000050 = (unsigned short)(a | 0xC0);
    i = 0x10;
    do {
        *(volatile unsigned short *)0x04000054 = i;
        sub_080188B8();
        i--;
    } while (i >= 0);
}
