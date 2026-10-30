extern int sub_0800F4CC(int, int);
extern void sub_080137A0(void *, int, int);
extern unsigned char gUnknown_03003250[];

void sub_0800E974(void)
{
    unsigned int i = 0;
    do {
        sub_0800F4CC(i, 0);
        i++;
    } while (i <= 2);
    sub_080137A0(gUnknown_03003250, 0, 0x40);
}
