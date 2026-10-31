extern unsigned char gUnknown_030033EC[];
void sub_08005674(int arg0);
extern int sub_0802D74C(unsigned char *, signed char, unsigned int);

void sub_08042230(unsigned char *a)
{
    if (a[1] != 0)
        return;
    a[2] = 0;
    a[0] = 5;
    *(volatile unsigned short *)0x04000000 = (unsigned short)(*(volatile unsigned short *)0x04000000 & 0x9FFF);
    sub_08005674(3);
    sub_0802D74C(gUnknown_030033EC, gUnknown_030033EC[-1], 0);
}
