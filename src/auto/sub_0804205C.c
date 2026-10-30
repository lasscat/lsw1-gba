extern void sub_0802D4B4(int, int, int);
extern unsigned char gUnknown_03006B1C[];

void sub_0804205C(unsigned char *a)
{
    unsigned char flag = a[1];

    if (flag == 0) {
        sub_0802D4B4(*(int *)(a + 4), 1, 4);
        sub_0802D4B4(*(int *)(a + 8), 1, 4);
        sub_0802D4B4(*(int *)(a + 12), 1, 4);
        sub_0802D4B4(*(int *)(a + 16), 1, 4);
        a[2] = flag;
        a[0] = 5;
    }

    if (gUnknown_03006B1C[0x2A6] == 1)
        gUnknown_03006B1C[0x2A5] = 1;
}
