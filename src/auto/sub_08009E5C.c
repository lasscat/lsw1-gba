extern void sub_0800A040(void);
extern void sub_0800A550(int *, int);
extern void sub_0800A8B0(void *);
extern void *sub_080135D0(int);
extern int gUnknown_03003190[];
extern int gUnknown_03002F30;
extern unsigned char gUnknown_03004980[];

void sub_08009E5C(void)
{
    sub_0800A550(gUnknown_03003190, 0x5000000);
    sub_0800A550(&gUnknown_03003190[2], 0x5000200);
    sub_0800A040();
    gUnknown_03002F30 = (int)sub_080135D0(0x400);
    if ((gUnknown_03004980[0xD] & 0x80) == 0)
        sub_0800A8B0((void *)0x080481E4);
    else
        sub_0800A8B0((void *)0x08048204);
}
