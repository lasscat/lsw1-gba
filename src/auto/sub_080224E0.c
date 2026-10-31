extern void sub_080004C0(void *);
extern void sub_08005870(int, int, int, int, int, int);
extern void sub_0800A040(void);
extern unsigned int sub_08013D88(void);
extern void sub_08018840(unsigned short, unsigned int);
extern void sub_0801DF88(void);
extern int gUnknown_03006AFC[];
extern unsigned char gUnknown_030024EC[];

void sub_080224E0(void)
{
    if (gUnknown_03006AFC[1] == 0) {
        sub_08018840(0x3f, 2);
    } else {
        sub_08005870(1, 0, 0, 0x20, 0x40, 0);
        if (sub_08013D88() == 3)
            sub_08005870(0, 0, 0, 0x20, 0x40, 0);
        sub_08005870(2, 0, 0, 0x20, 0x40, 0);
    }
    sub_0801DF88();
    sub_080004C0(gUnknown_030024EC);
    sub_0800A040();
}
