extern int *gUnknown_030034A4;
extern unsigned int gUnknown_03006B18;

extern void sub_080125F8(void);
extern void sub_08013D0C(void);

void sub_080188B8(void)
{
    int *p;
    int aa;
    int bb;
    int d1;
    int d2;

    do {
        sub_080125F8();
        p = gUnknown_030034A4;
        aa = p[7];
        bb = p[8];
        d1 = aa - bb;
        d2 = bb - aa;
        if (d1 >= 0)
            d2 = d1;
    } while ((unsigned int)d2 < gUnknown_03006B18);
    p[8] = aa;
    sub_08013D0C();
}
