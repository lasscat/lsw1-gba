extern unsigned char gUnknown_03002E14[];

void sub_080077F8(int a, int b, int c)
{
    int base = (int)gUnknown_03002E14;
    int r3 = c * 0x54;
    int r2 = base + 0x18;
    r2 = r2 + r3;
    *(int *)r2 = a;
    *(int *)(r2 + 4) = b;
    r3 = r3 + base;
    *(int *)r3 = a;
    *(int *)(r3 + 4) = b;
}
