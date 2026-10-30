extern unsigned char gUnknown_03002C50[];

void sub_08006DEC(int a, int b, int c)
{
    int r3;
    int r4;
    int r0;
    r4 = (int)gUnknown_03002C50;
    r3 = 0x64;
    r3 *= a;
    r0 = r4 + 0x28;
    r0 += r3;
    *(int *)r0 = b << 16;
    r0 = r4 + 0x2c;
    r0 += r3;
    *(int *)r0 = c << 16;
    r3 += r4;
    r3 += 0x44;
    *(unsigned short *)r3 |= 1;
}
