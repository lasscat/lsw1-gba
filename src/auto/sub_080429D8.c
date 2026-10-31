extern unsigned char gUnknown_0300332C[];
extern unsigned char gUnknown_03006B1C[];

void sub_08013DB4(unsigned int arg0);
void sub_08013DEC(unsigned int arg0, unsigned int arg1, unsigned int arg2);
unsigned int sub_0802CC4C(int arg0);
extern void sub_08042808(void);

typedef struct {
    unsigned char a[12];
    unsigned short b;
    unsigned char c[110];
} S_D8;

void sub_080429D8(void)
{
    unsigned int i;
    unsigned int v;
    unsigned char *gp;
    unsigned char *d;
    unsigned char *s;

    gp = gUnknown_03006B1C;
    v = gp[0x445];
    if (v != 0) {
        sub_08013DB4(0x10);
        return;
    }
    if (gp[0x293] == 0x2c) {
        if (sub_0802CC4C(0)) {
            if (sub_0802CC4C(1)) {
                if (sub_0802CC4C(2)) {
                    sub_08013DB4(0xe);
                    return;
                }
            }
        }
        for (i = 0; i <= 2; i++) {
            if (sub_0802CC4C(i) == 0) {
                sub_08013DEC(0x13, i, 0);
                break;
            }
        }
        return;
    }
    i = gUnknown_0300332C[0xB9];
    ((S_D8 *)gUnknown_0300332C)[i].b = v;
    i = 0;
    s = gp + 0x299;
    d = gUnknown_0300332C + 0xB7;
    do {
        *d++ = *s;
        i++;
    } while (i == 0);
    sub_08042808();
}
