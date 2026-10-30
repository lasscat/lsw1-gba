extern void sub_080004C0(void *);
extern void sub_08018840(unsigned short, unsigned int);
extern void sub_0801C2CC(void);
extern unsigned int gUnknown_03006AFC[];
extern unsigned int gUnknown_030024EC;

void sub_080207D0(void)
{
    if (gUnknown_03006AFC[1] == 0) {
        sub_08018840(0x3f, 2);
    }
    sub_0801C2CC();
    sub_080004C0(&gUnknown_030024EC);
}
