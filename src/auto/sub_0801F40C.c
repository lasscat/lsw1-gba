extern int gUnknown_03006AFC[];
extern unsigned char gUnknown_030024EC[];
extern void sub_08005870(int page, int column, int row, int width, int height, int value);
extern void sub_08018840(unsigned short, unsigned int);
extern void sub_0801DF88(void);
extern void sub_080004C0(void *);
extern void sub_0800A040(void);
void sub_0801F40C(void)
{
    if (gUnknown_03006AFC[1] == 0)
    {
        sub_08018840(0x3f, 2);
    }
    else
    {
        int x;
        int y;
        sub_08005870(1, 0, 0, 0x20, (x = 0x40), (y = 0));
        sub_08005870(0, 0, 0, 0x20, x, y);
    }
    sub_0801DF88();
    sub_080004C0(gUnknown_030024EC);
    sub_0800A040();
}
