extern void sub_080004C0(void *);
extern void sub_08018840(unsigned short, unsigned int);
extern void sub_0801C210(int);
extern void sub_080466D8(void);
extern void sub_08046784(unsigned int, unsigned int);

extern unsigned int gUnknown_03006AFC[];
extern unsigned int gUnknown_030024EC;
extern unsigned int gUnknown_030036BC;
extern unsigned char *gUnknown_030069D8;

void sub_080216D8(void)
{
    if (gUnknown_03006AFC[1] == 0) {
        sub_08018840(0x3f, 2);
    }
    sub_080004C0(&gUnknown_030024EC);
    sub_08046784(0, 0);
    sub_080466D8();
    if (gUnknown_030036BC == 4) {
        sub_0801C210(gUnknown_030069D8[0x79]);
    } else {
        sub_0801C210(0);
    }
}
