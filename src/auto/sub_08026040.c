extern void sub_080004C0(void *);
extern void sub_0800A040(void);
extern void sub_0801603C(void);
extern void sub_0801607C(void);
extern void sub_08018840(unsigned short, unsigned int);
extern unsigned int gUnknown_03006AFC[];
extern unsigned char gUnknown_030024EC[];

void sub_08026040(void)
{
    if (gUnknown_03006AFC[1] == 0)
        sub_08018840(0x3f, 2);
    sub_080004C0(gUnknown_030024EC);
    sub_0801603C();
    sub_0801607C();
    sub_0800A040();
}
