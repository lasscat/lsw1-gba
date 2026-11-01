extern unsigned char gUnknown_08E08B9C[];
extern unsigned char gUnknown_08052182[];
extern unsigned char gUnknown_03000158[];
extern unsigned char gUnknown_03000160[];
extern unsigned char gUnknown_03000168[];
extern unsigned char gUnknown_03000170[];
extern unsigned char gUnknown_03000178[];
extern unsigned char gUnknown_03000180[];
extern unsigned char gUnknown_03000188[];
extern unsigned char gUnknown_03000190[];
extern unsigned char gUnknown_03000198[];
extern unsigned char gUnknown_030001A0[];
extern unsigned char gUnknown_0892AC30[];

extern int gUnknown_0300368C[];
struct Slots {
    void *slot[14];
};
extern struct Slots *gUnknown_030072F8;

extern int sub_08005B3C(int a, void *b, unsigned short c, unsigned short d, int e, int f);
extern void sub_08009F98(int a, int b, int c);
extern void *sub_0802D28C(int arg0, int arg1, int arg2, int arg3);

void sub_0804048C(void)
{
    int found;
    int x;
    int y;
    unsigned int i;
    unsigned char *tbl;

    sub_08005B3C(2, gUnknown_08E08B9C, 0x2E, 0, 0, 0);
    found = 0;
    x = 8;
    y = 0x61;
    i = 0;
    tbl = gUnknown_08052182;
    for (; i < 14; i++) {
        unsigned int off = i * 2 + gUnknown_0300368C[2] * 0x34;
        unsigned int v = *(unsigned short *)(tbl + off);
        void *p;

        if (v == 0)
            found = 1;
        if (found) {
            gUnknown_030072F8->slot[i] = 0;
        } else {
            switch (v) {
            case 0x40: p = gUnknown_03000158; break;
            case 0x80: p = gUnknown_03000160; break;
            case 0x10: p = gUnknown_03000168; break;
            case 0x20: p = gUnknown_03000170; break;
            case 0x200: p = gUnknown_03000188; break;
            case 0x100: p = gUnknown_03000190; break;
            case 4: p = gUnknown_03000198; break;
            case 8: p = gUnknown_030001A0; break;
            case 1: p = gUnknown_03000178; break;
            case 2: p = gUnknown_03000180; break;
            default: p = 0; break;
            }
            gUnknown_030072F8->slot[i] = sub_0802D28C(x, y, (int)p, 1);
        }
        x += 0x22;
        if (i == 6) {
            x = 8;
            y += 0x22;
        }
    }
    sub_08009F98((int)gUnknown_0892AC30, 0x10, 0x10);
}
