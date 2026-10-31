extern void sub_0802D488(void *arg0);
extern void sub_0802D4B4(int, int, int);
extern unsigned char gUnknown_03006B1C[];
extern unsigned char gUnknown_08071648[];

void sub_08041D1C(unsigned char *a)
{
    if (a[1] != 0) {
        *(int *)(*(int *)(a + 8) + 0x10) = gUnknown_08071648[a[1] - 1] << 16;
    }
    if (a[1] == 0) {
        sub_0802D4B4(*(int *)(a + 4), 3, 4);
        sub_0802D4B4(*(int *)(a + 12), 1, 4);
        sub_0802D4B4(*(int *)(a + 16), 1, 4);
        sub_0802D4B4(*(int *)(a + 20), 1, 4);
        sub_0802D488(*(void **)(a + 8));
        a[2] = 0;
        a[0] = 5;
    }
    if (gUnknown_03006B1C[0x2A0] == 1)
        gUnknown_03006B1C[0x29F] = 1;
}
