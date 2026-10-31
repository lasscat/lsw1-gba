extern unsigned int gUnknown_03003430[];

unsigned int sub_0801346C(unsigned int, unsigned int);
unsigned int sub_08013490(unsigned int, unsigned int, unsigned int *);

void sub_080121E0(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int q;
    gUnknown_03003430[0x2c / 4] = b;
    gUnknown_03003430[0x30 / 4] = c;
    gUnknown_03003430[0x34 / 4] = d;
    gUnknown_03003430[0x14 / 4] = sub_0801346C(b + c - 1, c);
    gUnknown_03003430[0x18 / 4] = 0;
    q = sub_08013490(a, c, &gUnknown_03003430[0x28 / 4]);
    gUnknown_03003430[0x1c / 4] = q;
    if (q >= d) {
        unsigned int t = q + 1;
        gUnknown_03003430[0x18 / 4] = t - d;
        gUnknown_03003430[0x1c / 4] = d - 1;
    }
}
