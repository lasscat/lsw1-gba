typedef struct {
    int mode;
    signed char idx;
} State;

extern State *gUnknown_030069F0;
extern State gUnknown_03006A2C;
extern unsigned char gUnknown_03006B1C[];
extern struct { int a; int b; } gUnknown_0300368C;
extern int gUnknown_0804CB70;
extern int gUnknown_0804CB68;
extern int gUnknown_0804CB6C;
extern int gUnknown_0804CB5C[];
extern unsigned char gUnknown_0892B01C[];

extern void sub_0801E458(unsigned char a);
extern void sub_0802534C(void);
extern void sub_0800554C(unsigned short mode);
extern void sub_08005648(unsigned short a);
extern void sub_080053D4(unsigned int a, unsigned int b);
extern void sub_08005674(int arg0);
extern void sub_08009F98(int a, int b, int c);
extern void sub_08006988(int index, int x, int y);
extern void sub_080054F4(unsigned char);
extern void sub_0801C210(int a);
extern void sub_08046784(unsigned int a, unsigned int b);
extern int sub_08005AE8(int a, void *b, unsigned short c, unsigned short d, int e, int f);
extern void sub_08005470(int a, int b);
extern void sub_080054C4(unsigned char);
extern void sub_0802216C(void);
extern void sub_08021FEC(int a);
extern void sub_080187F8(unsigned short a, int b);

void sub_08021B8C(void)
{
    int s;

    sub_0801E458(0);
    gUnknown_030069F0 = &gUnknown_03006A2C;
    sub_0802534C();
    sub_0800554C(0);
    sub_08005648(0x1000);
    sub_080053D4(0, gUnknown_0804CB70);
    sub_08005674(0);
    sub_08009F98((int)gUnknown_0892B01C, 1, 15);
    sub_080053D4(1, gUnknown_0804CB68);
    sub_08005674(1);
    sub_08006988(1, 0, 0);
    sub_080053D4(2, gUnknown_0804CB6C);
    sub_08005674(2);
    sub_08006988(2, 0, 0);
    sub_080054F4(3);
    sub_0801C210(0);
    sub_08046784(gUnknown_03006B1C[0x281], 1);
    s = gUnknown_0300368C.b;
    if (s == 0) {
        gUnknown_030069F0->idx = s;
        sub_08005AE8(1, (void *)gUnknown_0804CB5C[gUnknown_030069F0->idx], 0, 0, 0, 0);
        gUnknown_030069F0->mode = 1;
    } else if (s == 1) {
        gUnknown_030069F0->idx = s;
        sub_08005AE8(2, (void *)gUnknown_0804CB5C[gUnknown_030069F0->idx], 0, 0, 0, 0);
        sub_08005470(1, 2);
        sub_080054C4(2);
        sub_080054F4(1);
        sub_08005470(2, 1);
        gUnknown_030069F0->mode = 2;
    } else if (s == 2) {
        gUnknown_030069F0->idx = s;
        sub_08005AE8(1, (void *)gUnknown_0804CB5C[gUnknown_030069F0->idx], 0, 0, 0, 0);
        gUnknown_030069F0->mode = 1;
    }
    if (gUnknown_03006B1C[0x293] == 0x2C)
        sub_0801C210(0);
    gUnknown_03006B1C[0x291] = gUnknown_030069F0->idx;
    sub_0802216C();
    gUnknown_030069F0->idx++;
    sub_08021FEC(1);
    gUnknown_030069F0->idx--;
    sub_08021FEC(0xFFFF);
    sub_080187F8(0x3F, 2);
}
