void sub_0802D4B4(int a, int b, int c);

struct S4161C {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char pad[9];
    int fC;
    int f10;
    int f14;
    int f18;
};

void sub_0804161C(struct S4161C *p)
{
    if (p->f1 == 0) {
        sub_0802D4B4(p->fC, 0, 0);
        sub_0802D4B4(p->f10, 0, 0);
        sub_0802D4B4(p->f14, 0, 0);
        sub_0802D4B4(p->f18, 0, 0);
        p->f2 = 0;
        p->f0 = 5;
    }
}
