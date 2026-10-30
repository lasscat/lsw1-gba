extern int *gUnknown_030034A4;
extern int gUnknown_0300366C;

void sub_080129B4(void)
{
    gUnknown_030034A4[3]++;
    *(volatile unsigned short *)0x04000202 = 8;
    gUnknown_0300366C |= 8;
}
