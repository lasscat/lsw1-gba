extern unsigned int gUnknown_0300673C;
extern unsigned char gUnknown_03006740[];
extern unsigned char gUnknown_030067B0[];
extern unsigned int gUnknown_03006738;
void sub_08013828(void *, int, int);

void sub_0801DFB4(void)
{
    if (gUnknown_0300673C != 0) {
        sub_08013828(gUnknown_03006740, (int)gUnknown_030067B0, 0x70);
        gUnknown_0300673C = 0;
    }
    gUnknown_03006738 = 0;
    *(volatile unsigned short *)0x04000004 &= 0xff;
    *(volatile unsigned short *)0x04000004 |= gUnknown_03006740[0] << 8;
}
