struct Sub140E8A {
    char pad[112];
    signed char f0;
    signed char f1;
    signed char f2;
    signed char f3;
};

struct Sub140E8B {
    int f0;
    int f1;
    int f2;
    int f3;
};

void sub_080140E8(struct Sub140E8A *a, struct Sub140E8B *b)
{
    b->f2 = a->f2;
    b->f3 = a->f3;
    b->f1 = a->f1;
    b->f0 = a->f0;
}
