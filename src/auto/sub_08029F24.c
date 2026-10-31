extern int sub_08005AE8(int, void *, unsigned short, unsigned short, int, int);
extern int sub_08005B3C(int, void *, unsigned short, unsigned short, int, int);
extern void sub_080068B4(int, int, int, unsigned short);
extern void sub_08005870(int, int, int, int, int, int);
extern void sub_0801BEB8(int);
extern int sub_08011F3C(int *, unsigned int, unsigned int, unsigned int, int);
extern void sub_08006AF0(int, int, int);
extern void sub_08013DB4(unsigned int);
extern void sub_0802A194(int, int *);

extern unsigned int gUnknown_0300368C[];
struct Input { unsigned int pad; unsigned short keys; };
extern struct Input gUnknown_03003430;
extern unsigned char gUnknown_0300332C[];
extern unsigned char gUnknown_03004980[];

void sub_08029F24(void)
{
    unsigned int *p = gUnknown_0300368C;
    int value;
    switch (p[4]) {
    case 0:
        if (p[5] == 20) {
            sub_08005B3C(2, (void *)0x08E2EC2C, 1, 0, 0, 0);
            sub_08005AE8(1, (void *)0x08E31D10, 0xa3, 0, 0, 0);
            sub_080068B4(0, 0, 0xa00000, p[5]);
            sub_080068B4(1, 0, 0xa00000, p[5]);
            sub_080068B4(2, 0, 0, p[5]);
            value = 0xaf;
            sub_0802A194(1, &value);
            sub_0802A194(2, &value);
        }
        if (p[5] == 0) {
            p[2] = 0;
            p[4] = 2;
        }
        break;
    case 1:
        if ((gUnknown_03003430.keys & 1) ||
            (gUnknown_03003430.keys & 8)) {
            sub_0801BEB8(5);
            sub_08005870(0, 0, 0, 0x20, 0x40, 0);
            value = 0xaf;
            sub_0802A194(1, &value);
            sub_0802A194(2, &value);
            p[2] = 0;
            p[4] = 2;
        }
        return;
    case 2:
        if (gUnknown_03003430.keys & 0xc0) {
            if (sub_08011F3C((int *)&p[2], 0, 1, 0, gUnknown_0300332C[0xb9])) {
                sub_0801BEB8(0);
                sub_08006AF0(1, 0, 160 - p[2] * 14);
            }
        } else if (gUnknown_03003430.keys & 1) {
            switch (p[2]) {
            case 0:
                sub_0801BEB8(1);
                p[3] = 12;
                p[4] = 3;
                p[5] = 20;
                break;
            case 1:
                if (gUnknown_03004980[13] & 3) {
                    sub_0801BEB8(1);
                    p[3] = 11;
                    p[4] = 3;
                    p[5] = 20;
                } else {
                    sub_0801BEB8(17);
                }
            }
        }
        return;
    case 3:
        if (p[5] == 20) {
            sub_080068B4(0, 0, 0, 20);
            sub_080068B4(1, 0, 0, p[5]);
            sub_080068B4(2, 0, 0xa00000, p[5]);
        }
        if (p[5] == 0)
            sub_08013DB4(p[3]);
        break;
    default:
        return;
    }
    p[5]--;
}
