void sub_0800EABC(int a, int b, int c, int d);
int sub_0802CBD0(void);
int *sub_0802D408(int a, int b, int c, int d);
extern int gUnknown_0804CB7C[];
struct U080226AC { int *v[5]; };
extern struct U080226AC *gUnknown_030069F4;

void sub_0802256C(void)
{
    unsigned int i;

    sub_0800EABC(0, 9, 0, 0);
    i = 0;
    do {
        if (i == 1 && sub_0802CBD0() == 0)
            sub_0800EABC(0, 11, 0, 0);
        else
            sub_0800EABC(0, 9, 0, 0);
        gUnknown_030069F4->v[i] = sub_0802D408(i + 9, 0x78, gUnknown_0804CB7C[i] + 0x65, 1);
        i++;
    } while (i <= 2);
}
