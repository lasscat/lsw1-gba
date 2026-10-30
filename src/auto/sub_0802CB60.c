extern unsigned int gUnknown_03006B1C;

void sub_0802CB60(int a, int b)
{
    unsigned int *r4 = (unsigned int *)(unsigned int)&gUnknown_03006B1C;
    unsigned int r2 = 0x88 << 3;
    r4 = (unsigned int *)((unsigned int)r4 + r2);
    {
        unsigned int r3 = 1 << a;
        r2 = *r4;
        r2 &= ~r3;
        r2 += ((unsigned int)b << a);
        *r4 = r2;
    }
}
