extern int gUnknown_03002F34;
extern int gUnknown_03003198;

struct S0800AB3C {
    unsigned short a;
    unsigned short b;
    int c;
};

extern struct S0800AB3C gUnknown_03003090[];

void sub_0800A584(int a, int b, int c, int *d);

void sub_0800AB3C(void)
{
    unsigned int i = 0;

    if (i < gUnknown_03002F34) {
        do {
            sub_0800A584(gUnknown_03003090[i].c, gUnknown_03003090[i].a, gUnknown_03003090[i].b, &gUnknown_03003198);
            i++;
        } while (i < gUnknown_03002F34);
    }
    gUnknown_03002F34 = 0;
}
