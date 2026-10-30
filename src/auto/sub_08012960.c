extern int *gUnknown_030034A4;
extern unsigned int gUnknown_0300366C;

void sub_08012960(void)
{
    void (*f)(void) = (void (*)(void))gUnknown_030034A4[2];

    if (f)
        f();
    gUnknown_030034A4[10]++;
    *(volatile unsigned short *)0x04000202 = 4;
    gUnknown_0300366C |= 4;
}
