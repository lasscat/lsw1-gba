extern void sub_080188B8(void);

void sub_08018950(unsigned short r0)
{
    int i;

    *(volatile unsigned short *)0x04000050 = r0 | 0xc0;
    i = 0;
    do
    {
        *(volatile unsigned short *)0x04000054 = i;
        sub_080188B8();
        i += 2;
    } while (i <= 0xf);
}
