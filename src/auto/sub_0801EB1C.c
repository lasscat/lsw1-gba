extern unsigned char gUnknown_03006924[];

void sub_0801EB1C(int a, int b, int c, int d, unsigned short e)
{
    unsigned char *p = gUnknown_03006924 + a * 60;
    p += b * 28 + 4;
    *(int *)(p + 0x14) = c;
    *(int *)(p + 0x18) = d;
    *(unsigned short *)(p + 0x02) = e;
    {
        unsigned short t = *(unsigned short *)p;
        t |= 2;
        *(unsigned short *)p = t;
    }
}
