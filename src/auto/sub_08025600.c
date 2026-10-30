extern int gUnknown_03006AFC[];
extern int gUnknown_030024EC[];
extern void sub_08018840(unsigned short, unsigned int);
extern void sub_080004C0(void *);
extern void sub_0800A040(void);

void sub_08025600(void)
{
    if (gUnknown_03006AFC[1] == 0)
        sub_08018840(63, 2);
    sub_080004C0(gUnknown_030024EC);
    sub_0800A040();
}
