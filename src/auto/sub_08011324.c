extern unsigned char gUnknown_0300332C[];

struct Sub11324 {
    unsigned char pad[0xC];
    int f0c;
    int f10;
    unsigned char pad2[0x2C];
    int f40;
};

int sub_08033374(int a, int b);
void sub_080312B0(int a, int b, int c, int d, int e, int f, int g, void *h);

void sub_08011324(struct Sub11324 *p)
{
    unsigned int addr = (unsigned int)gUnknown_0300332C;
    int a;
    int b;
    int c;

    if ((*(unsigned int *)(addr + 0x8C) & 0x800) != 0) {
        sub_08033374(sub_08033374((int)p, 0x21), 0x34);
        c = 100;
        a = 0x2C0000;
        b = 0xE0000;
    } else {
        sub_08033374(sub_08033374((int)p, 0x20), 0x12);
        c = 50;
        a = 0x280000;
        b = 0xA0000;
    }
    if (gUnknown_0300332C[0xCF] != 0)
        c *= 4;
    if ((*(unsigned int *)(gUnknown_0300332C + 0x8C) & 0x80) != 0)
        c *= 2;
    sub_080312B0(p->f0c, p->f10, p->f40, a, b, c, 6, p);
}
