extern unsigned char gUnknown_03006924[];

void sub_0801EABC(int a, int b, int c, int d, int e)
{
    unsigned char *p = gUnknown_03006924 + a * 60;
    *(int *)(p + 8) = b;
    *(int *)(p + 12) = c;
    *(int *)(p + 0x24) = d;
    *(int *)(p + 0x28) = e;
    *(volatile unsigned short *)(0x04000040 + a * 2) = (b >> 16 << 8) | (d >> 16);
    *(volatile unsigned short *)(0x04000044 + a * 2) = (c >> 16 << 8) | (e >> 16);
}
