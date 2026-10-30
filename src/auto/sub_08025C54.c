extern void sub_0801E458(int a);
extern void sub_0801E224(void);
extern void sub_0802534C(void);
extern void sub_0800554C(int a);
extern void sub_08005648(unsigned short a);
extern void sub_080053D4(unsigned int a, unsigned int b);
extern void sub_08006AF0(int a, int b, int c);
extern void sub_0800569C(int a, unsigned short b);
extern void sub_08005DCC(void *a, int b, int c);
extern void sub_0800E9B4(unsigned int a);
extern void sub_080262D4(void);
extern void sub_080263FC(void);
extern void sub_08046784(unsigned int a, unsigned int b);
extern void sub_0801C210(int a);
extern void sub_08029D14(void);
extern void sub_080187F8(unsigned short a, int b);

extern unsigned char gUnknown_03006690[];
extern unsigned char gUnknown_03006A2C[];
extern void *gUnknown_03006AEC;
extern unsigned int gUnknown_03006AFC[];
extern unsigned int gUnknown_0300368C[];
extern unsigned char gUnknown_03006B1C[];

void sub_08025C54(void)
{
    unsigned int *p6afc;
    unsigned int r4;

    sub_0801E458(0);
    sub_0801E224();
    gUnknown_03006AEC = gUnknown_03006A2C;
    sub_0802534C();

    p6afc = gUnknown_03006AFC;
    if (p6afc[1] == 0) {
        sub_0800554C(0);
        sub_08005648(0x1000);
    }

    sub_080053D4(1, *(unsigned int *)0x0804E9A4);
    r4 = *(unsigned int *)0x0804E9A8;
    sub_080053D4(0, r4);
    sub_08006AF0(0, 0, 0);
    sub_08006AF0(1, 0, 0);
    sub_0800569C(0, 0);
    sub_08005DCC((void *)0x0892B018, 0, 0x10);
    sub_0800E9B4(r4);
    sub_080262D4();
    gUnknown_0300368C[4] = 0;
    sub_080263FC();

    {
        unsigned char *p;
        unsigned char v;
        p = gUnknown_03006B1C;
        v = p[0x281];
        sub_08046784(v, 1);
        p = p + 0x466;
        if (*p == 0x3d) {
            unsigned char old = gUnknown_03006690[5];
            gUnknown_03006690[5] = 0;
            sub_0801C210(old);
        }
        *p = 0;
    }

    if (p6afc[1] == 0) {
        sub_08029D14();
        sub_080187F8(0x3f, 2);
    }
}
