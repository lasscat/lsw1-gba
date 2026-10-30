extern void sub_080188B8(void);

void sub_08018998(unsigned short r0)
{
    int r4;

    *(volatile unsigned short *)0x04000050 = r0 | 0x80;
    r4 = 0x10;
    do
    {
        *(volatile unsigned short *)0x04000054 = r4;
        sub_080188B8();
        r4 -= 2;
    } while (r4 >= 0);
}
