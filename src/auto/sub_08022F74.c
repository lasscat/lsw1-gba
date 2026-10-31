extern void sub_08018840(unsigned short, unsigned int);
extern void sub_080004C0(void *);
extern unsigned char gUnknown_030024EC[];
void sub_08005674(int arg0);
void sub_080054F4(unsigned char arg0);

void sub_08022F74(void)
{
    sub_08018840(0x3f, 2);
    sub_080004C0(gUnknown_030024EC);
    sub_08005674(0);
    sub_08005674(1);
    sub_08005674(2);
    sub_08005674(3);
    sub_080054F4(0);
    sub_080054F4(1);
    sub_080054F4(2);
    sub_080054F4(3);
}
