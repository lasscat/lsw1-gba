extern void sub_0801E458(unsigned char a);
extern void sub_0800554C(unsigned short mode);
extern void sub_08005648(unsigned short a);
extern void sub_080054F4(unsigned char a);
extern void sub_0802534C(void);
extern int sub_08005DCC(unsigned char *a, int b, int c);
extern void sub_080053D4(unsigned int a, unsigned int b);
extern void sub_08005674(int arg0);
extern void sub_08006AF0(int a, int b, int c);
extern void sub_08009F98(int a, int b, int c);
extern void sub_0801C210(int a);
extern void sub_08046784(unsigned int a, unsigned int b);
extern void sub_08029D14(void);
extern void sub_080187F8(unsigned short a, int b);

extern unsigned int gUnknown_03006AFC[];
extern void *gUnknown_030069F4;
extern unsigned char gUnknown_03006A2C[];
extern unsigned char gUnknown_03006B1C[];
extern unsigned int gUnknown_0300368C[];
extern unsigned char gUnknown_0300332C[];

void sub_080221C8(void)
{
    unsigned char *p;

    sub_0801E458(0);
    if (gUnknown_03006AFC[1] == 0) {
        sub_0800554C(0);
        sub_08005648(0x1000);
    } else {
        sub_080054F4(0);
    }
    gUnknown_030069F4 = gUnknown_03006A2C;
    sub_0802534C();
    sub_08005DCC((unsigned char *)0x08E3039C, 0, 0x10);
    sub_080053D4(1, *(unsigned int *)0x0804CB74);
    sub_08005674(1);
    sub_08006AF0(1, 0, 0x48);
    sub_080053D4(2, *(unsigned int *)0x0804CB78);
    sub_08005674(2);
    sub_08006AF0(2, 0, 0);
    sub_08009F98(0x0892B01C, 1, 15);
    sub_0801C210(0);
    p = gUnknown_03006B1C;
    sub_08046784(p[0x281], 1);
    gUnknown_0300368C[4] = 0;
    p[0x445] = 0;
    gUnknown_0300368C[5] = 1;
    if (gUnknown_03006AFC[1] == 0) {
        sub_08029D14();
        sub_080187F8(0x3f, 2);
    }
    gUnknown_0300332C[0xBE] = 0;
}
