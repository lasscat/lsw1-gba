extern unsigned int gUnknown_03002E14[];

struct P {
    unsigned int x;
    unsigned int y;
};

void sub_080079AC(struct P *a, struct P *b, unsigned int c, unsigned int d)
{
    unsigned int v = gUnknown_03002E14[8] | gUnknown_03002E14[9] | gUnknown_03002E14[10] | gUnknown_03002E14[11];

    if (v != 0) {
        *a = *(struct P *)&gUnknown_03002E14[8];
        *b = *(struct P *)&gUnknown_03002E14[10];
    } else {
        a->x = v;
        a->y = v;
        b->x = c;
        b->y = d;
    }
}
