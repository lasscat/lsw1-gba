struct S_30034A4
{
    int unk0;
    void (*func)(void);
    int unk8[7];
    int count;
};

extern struct S_30034A4 *gUnknown_030034A4;
extern unsigned int gUnknown_0300366C;

void sub_0801290C(void)
{
    if (gUnknown_030034A4->func != 0)
        gUnknown_030034A4->func();
    gUnknown_030034A4->count++;
    *(volatile unsigned short *)0x04000202 = 2;
    gUnknown_0300366C |= 2;
}
