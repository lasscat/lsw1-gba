extern int gUnknown_03006AFC[];
extern void *gUnknown_030072F8;
extern unsigned char gUnknown_03006A2C[];
extern unsigned char gUnknown_03006B1C[];
extern int gUnknown_0300368C[];
extern unsigned int gUnknown_08070A20;
extern unsigned int gUnknown_08070A1C;
extern unsigned int gUnknown_08070A18;
extern unsigned char gUnknown_0892B018[];
extern unsigned char gUnknown_08070A24[];
extern unsigned char gUnknown_08070A33[];
extern void sub_080053D4(unsigned int a, unsigned int b);
extern void sub_080054C4(unsigned char);
extern void sub_0800554C(unsigned short mode);
extern void sub_08005648(unsigned short a);
extern void sub_08005674(int arg0);
extern void sub_0800569C(int a, unsigned short b);
extern int sub_08005DCC(unsigned char *a, int b, int c);
extern void sub_08006988(int index, int x, int y);
extern void sub_08006AF0(int a, int b, int c);
extern void sub_0800E9B4(unsigned int a);
extern void sub_080187F8(unsigned short a, int b);
extern void sub_0801C210(int a);
extern void sub_0801E458(unsigned char a);
extern void sub_0802534C(void);
extern void sub_08029D14(void);

void sub_08040004(void)
{
    unsigned int v;
    sub_0801E458(0);
    gUnknown_030072F8 = gUnknown_03006A2C;
    sub_0802534C();
    if (gUnknown_03006AFC[1] == 0)
    {
        sub_0800554C(0);
        sub_08005648(0x1000);
    }
    sub_080053D4(1, gUnknown_08070A20);
    v = gUnknown_08070A1C;
    sub_080053D4(0, v);
    sub_080053D4(2, gUnknown_08070A18);
    sub_08005674(1);
    sub_08005674(0);
    sub_08005674(2);
    sub_080054C4(1);
    sub_080054C4(0);
    sub_080054C4(2);
    sub_0800569C(0, 0);
    sub_08006988(1, 0, 0);
    sub_08006AF0(0, 0, -0xa0);
    sub_08006AF0(2, 0, 0xa0);
    sub_08005DCC(gUnknown_0892B018, 0, 0x10);
    sub_0800E9B4(v);
    gUnknown_0300368C[4] = 0;
    gUnknown_0300368C[5] = 1;
    sub_0801C210(0x11);
    if (gUnknown_03006AFC[1] == 0)
    {
        sub_08029D14();
        sub_080187F8(0x3f, 2);
    }
    if (gUnknown_0300368C[1] == 0)
        gUnknown_0300368C[2] = gUnknown_08070A24[gUnknown_03006B1C[0x292]];
    else if (gUnknown_0300368C[1] == 1)
        gUnknown_0300368C[2] = gUnknown_08070A33[gUnknown_03006B1C[0x291]];
    else if (gUnknown_0300368C[1] == 2)
        gUnknown_0300368C[2] = 0x3d;
}
