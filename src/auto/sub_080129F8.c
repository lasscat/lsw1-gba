extern int *gUnknown_030034A4;
extern unsigned int gUnknown_0300366C;

void sub_080129F8(void)
{
    gUnknown_030034A4[6]++;
    *(volatile unsigned short *)0x04000202 = 0x40;
    gUnknown_0300366C |= 0x40;
}
