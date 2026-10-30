extern void *sub_080135D0(int);
extern void *sub_08012B88(void *, int, int);
extern void *gUnknown_03002734[];
extern void *gUnknown_03002BBC;
extern int gUnknown_0300297C;
extern unsigned short gUnknown_030024EC[];
extern unsigned char gUnknown_03002BC0;
extern int gUnknown_03002BC4;

void sub_08000180(void)
{
    void **p;
    gUnknown_03002734[0] = sub_080135D0(0xA668);
    p = &gUnknown_03002BBC;
    *p = sub_080135D0(0x34);
    gUnknown_03002734[1] = sub_08012B88(gUnknown_03002734[0], 0x8E, 0x12C);
    gUnknown_0300297C = 1;
    gUnknown_030024EC[4] = 0;
    gUnknown_030024EC[5] = 0;
    gUnknown_03002BC0 = 0x40;
    gUnknown_03002BC4 = 0;
}
