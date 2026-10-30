extern void sub_080004C0(void *);
extern void sub_0800A040(void);
extern void sub_08018840(unsigned short, unsigned int);
extern int gUnknown_03006AFC[];
extern unsigned char gUnknown_030024EC[];

void sub_08022A64(void)
{
    if (gUnknown_03006AFC[1] == 0)
        sub_08018840(0x3f, 2);
    sub_080004C0(gUnknown_030024EC);
    sub_0800A040();
}
