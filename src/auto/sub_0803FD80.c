typedef struct {
    int unk0;
    char *unk4;
    int unk8;
    int unkC;
    unsigned int state;
    int timer;
} S0300368C;

extern S0300368C gUnknown_0300368C;
extern unsigned char gUnknown_08E328C8[];
extern struct { int a; unsigned short keys; } gUnknown_03003430;

extern void sub_08005674(int arg0);
extern int sub_08005B3C(int a, void *b, unsigned short c, unsigned short d, int e, int f);
extern void sub_080068B4(int a, int b, int c, short d);
extern void sub_0800EABC(int a, int b, int c, int d);
extern int sub_0800ECF4(int a0, int a1, int a2, int a3, int a4, unsigned char **a5, int a6);
extern void sub_08013DB4(unsigned int arg0);
extern void sub_0801BEB8(int);
extern void *sub_0801D0AC(const char *a);
extern void sub_0802D00C(void);
extern void sub_0802D06C(void);
extern void sub_0803FF4C(void);
extern void sub_0803FFC8(void);

void sub_0803FD80(void)
{
    S0300368C *p = &gUnknown_0300368C;
    unsigned char *str;
    int n;

    switch (p->state) {
    case 0:
        n = --p->timer;
        if (n == -1) {
            sub_08005B3C(1, gUnknown_08E328C8, 1, 0, 0, 0);
            sub_080068B4(1, 0, 0xA00000, 20);
            sub_080068B4(0, 0, 0, 20);
            sub_0803FF4C();
            sub_08005674(0);
            sub_0800EABC(0, 9, 0, n);
            str = sub_0801D0AC(p->unk4);
            sub_0800ECF4(200, 74, 16, 130, 120, &str, 0);
            p->state = 1;
            p->timer = 20;
        }
        break;
    case 1:
        if (--p->timer == -1) {
            sub_0802D06C();
            p->state = 2;
        }
        break;
    case 4:
        if (--p->timer == -1) {
            sub_08013DB4(6);
            sub_08005674(0);
            sub_08005674(1);
            sub_08005674(2);
        }
        break;
    case 2:
        sub_0802D00C();
        if ((gUnknown_03003430.keys & 1) || (gUnknown_03003430.keys & 8)) {
            sub_0801BEB8(1);
            p->timer = 20;
            p->state = 4;
            sub_0803FFC8();
            sub_080068B4(1, 0, 0, 20);
            sub_080068B4(0, 0, 0xFF600000, 20);
            sub_080068B4(2, 0, 0, 20);
        }
        break;
    }
}
