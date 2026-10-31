extern void sub_0801E458(unsigned char a);
extern void sub_0802534C(void);
extern void sub_0800554C(unsigned short mode);
extern void sub_08005648(unsigned short a);
extern void sub_080053D4(unsigned int a, unsigned int b);
extern void sub_0800569C(int a, unsigned short b);
extern void sub_08005870(int a, int b, int c, int d, int e, int f);
extern void sub_0800E9B4(unsigned int a);
extern void sub_0802A254(void);
extern int sub_08005DCC(unsigned char *a, int b, int c);
extern void sub_08009F98(int a, int b, int c);
extern void sub_0801C210(int a);
extern void sub_08046784(unsigned int a, unsigned int b);
extern void sub_08029D14(void);
extern void sub_080187F8(unsigned short a, int b);

extern unsigned int gUnknown_03006AFC[];
extern unsigned char gUnknown_03006B1C[];
extern unsigned char gUnknown_0300332C[];

void sub_08029E14(void)
{
    unsigned int *p;
    unsigned int v;

    sub_0801E458(0);
    sub_0802534C();
    p = gUnknown_03006AFC;
    if (p[1] == 0) {
        sub_0800554C(0);
        sub_08005648(0x1000);
    }
    v = *(unsigned int *)0x0804F4FC;
    sub_080053D4(0, v);
    sub_080053D4(1, *(unsigned int *)0x0804F4F4);
    sub_080053D4(2, *(unsigned int *)0x0804F4F8);
    sub_0800569C(0, 0);
    sub_08005870(0, 0, 0, 0x20, 0x40, 0);
    sub_08005870(1, 0, 0, 0x20, 0x40, 0);
    sub_08005870(2, 0, 0, 0x20, 0x40, 0);
    sub_0800E9B4(v);
    sub_0802A254();
    sub_08005DCC((unsigned char *)0x08E2EC2C, 0, 0x10);
    sub_08009F98(0x0892B01C, 1, 15);
    sub_0801C210(0);
    sub_08046784(gUnknown_03006B1C[0x281], 1);
    if (p[1] == 0) {
        sub_08029D14();
        sub_080187F8(0x3f, 2);
    }
    gUnknown_0300332C[0xBE] = 0;
}
