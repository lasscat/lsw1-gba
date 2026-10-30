extern unsigned char gUnknown_03002C54[];

void sub_080068B4(int a, int b, int c, short d)
{
    unsigned char *p;
    a *= 100;
    p = gUnknown_03002C54 + a;
    *(int *)(p + 0x2C) = b;
    *(int *)(p + 0x30) = c;
    *(unsigned short *)(p + 0x42) = d;
    *(unsigned short *)(p + 0x40) |= 1;
}
