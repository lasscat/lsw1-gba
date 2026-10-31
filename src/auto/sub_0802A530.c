extern void sub_0800037C(unsigned int);
extern void sub_08016000(int);
extern void sub_0800A46C(int);
extern void sub_08015D30(int, int);
extern int gUnknown_03006B08;
extern int gUnknown_03006B0C;
extern int gUnknown_03006B10;

void sub_0802A530(unsigned int arg0)
{
    sub_0800037C(arg0);
    if (gUnknown_03006B08 != 0) {
        sub_08016000(gUnknown_03006B08);
        gUnknown_03006B08 = 0;
    }
    if (gUnknown_03006B0C != -1) {
        sub_0800A46C(gUnknown_03006B0C);
        gUnknown_03006B0C = -1;
    }
    if (gUnknown_03006B10 != 0) {
        gUnknown_03006B10 = 0;
        sub_08015D30(0, 0);
    }
}
