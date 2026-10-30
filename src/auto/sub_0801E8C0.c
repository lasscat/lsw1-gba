extern unsigned int gUnknown_03006824[];
extern unsigned int gUnknown_030068A4[];

void sub_0801E8C0(void)
{
    unsigned int i;
    unsigned int *a = gUnknown_03006824;
    unsigned int *b = gUnknown_030068A4;
    for (i = 0; i <= 31; i++) {
        a[i] &= b[i];
        b[i] = -1;
    }
}
