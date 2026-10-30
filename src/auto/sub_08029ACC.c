extern int sub_08018670(int a, int b);
extern void sub_0801C19C(unsigned int arg);
extern void sub_08018840(unsigned short, unsigned int);
extern void sub_080004C0(void *);
extern void sub_0801D858(void *);
extern void sub_0801C1D8(void);

extern unsigned int *gUnknown_03006AF8;
extern unsigned int gUnknown_030024EC;

void sub_08029ACC(void)
{
    sub_08018670(0, 0x1f);
    sub_0801C19C(gUnknown_03006AF8[21]);
    sub_08018840(0x3f, 2);
    sub_080004C0(&gUnknown_030024EC);
    if (gUnknown_03006AF8[18] != 0) {
        sub_0801D858((void *)((unsigned char *)gUnknown_03006AF8 + 8));
    }
    sub_0801C1D8();
}
