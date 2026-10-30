extern unsigned char gUnknown_03002E14[];

void sub_08008034(int val, int a)
{
    unsigned char *r2 = gUnknown_03002E14;
    int r3 = 0x54;
    int r1 = a * r3;
    r2 = r2 + 0x34;
    *(int *)(r1 + r2) = val;
}
