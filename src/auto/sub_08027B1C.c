struct S27B1C {
    unsigned char pad[0x6C];
    unsigned short f6C;
    unsigned short f6E;
    unsigned short f70;
    unsigned char f72;
    unsigned char pad73;
    unsigned int f74;
    unsigned char pad78[0x20];
    unsigned short f98[7];
};

struct T27B1C {
    unsigned char pad[0x10];
    unsigned int f10;
};

extern struct S27B1C *gUnknown_03006AF4;
extern struct S27B1C gUnknown_03006A2C;
extern struct T27B1C gUnknown_0300368C;
extern unsigned char gUnknown_03006B1C[];
extern unsigned int gUnknown_03006B14;
extern unsigned int gUnknown_0804EBF0;
extern unsigned int gUnknown_0804EBEC;
extern unsigned char gUnknown_08E28FB0[];
extern unsigned char gUnknown_08E2E1D4[];
extern unsigned char gUnknown_0892B018[];

void sub_0801E458(unsigned char a);
void sub_0802534C(void);
int sub_0802CB20(int arg0);
void sub_08029164(void);
void sub_0800554C(unsigned short mode);
void sub_08005648(unsigned short a);
void sub_080053D4(unsigned int a, unsigned int b);
void sub_0800569C(int a, unsigned short b);
int sub_08005B3C(int a, void *b, unsigned short c, unsigned short d, int e, int f);
int sub_08005DCC(unsigned char *a, int b, int c);
void sub_080289DC(void);
void sub_08029D14(void);
void sub_0801C210(int a);
void sub_080187F8(unsigned short a, int b);
void sub_08046784(unsigned int a, unsigned int b);

void sub_08027B1C(void)
{
    unsigned char *p;

    sub_0801E458(0);
    gUnknown_03006AF4 = &gUnknown_03006A2C;
    sub_0802534C();
    gUnknown_0300368C.f10 = 0;
    gUnknown_03006AF4->f70 = *(unsigned short *)((p = gUnknown_03006B1C) + 0x3B4);
    gUnknown_03006AF4->f6C = *(unsigned short *)(p + 0x3B2);
    gUnknown_03006AF4->f6E = *(unsigned short *)(p + 0x3B0);
    gUnknown_03006AF4->f74 = 0;
    gUnknown_03006AF4->f72 = sub_0802CB20(p[0x292]);
    if (gUnknown_03006AF4->f72 == 5)
        gUnknown_03006B14 |= 0x100;
    gUnknown_03006AF4->f98[0] = 0;
    gUnknown_03006AF4->f98[1] = 0;
    gUnknown_03006AF4->f98[2] = 0;
    gUnknown_03006AF4->f98[3] = 0;
    gUnknown_03006AF4->f98[4] = 0;
    gUnknown_03006AF4->f98[5] = 0;
    gUnknown_03006AF4->f98[6] = 0;
    sub_08029164();
    sub_0800554C(0);
    sub_08005648(0x1000);
    sub_080053D4(2, gUnknown_0804EBF0);
    sub_080053D4(1, gUnknown_0804EBEC);
    sub_0800569C(2, 0);
    sub_08005B3C(2, gUnknown_08E28FB0, 1, 0, 0, 0);
    sub_08005B3C(1, gUnknown_08E2E1D4, 0x3E, 0, 0, -10);
    sub_08005DCC(gUnknown_0892B018, 0, 0x10);
    sub_080289DC();
    sub_08029D14();
    sub_0801C210(0);
    sub_080187F8(0x3F, 2);
    sub_08046784(p[0x281], 1);
}
