extern unsigned int gUnknown_03006AFC[];
extern unsigned char gUnknown_030024EC[];
extern void sub_080004C0(void *);
extern void sub_08005870(int, int, int, int, int, int);
extern void sub_0800A040(void);
extern void sub_08018840(unsigned short, unsigned int);
extern void sub_0801DF88(void);

void sub_0804039C(void)
{
    if (gUnknown_03006AFC[1] == 0)
        sub_08018840(0x3F, 2);
    else
    {
        sub_08005870(1, 0, 0, 0x20, 0x40, 0);
        sub_08005870(0, 0, 0, 0x20, 0x40, 0);
    }
    sub_0801DF88();
    sub_080004C0(gUnknown_030024EC);
    sub_0800A040();
}
