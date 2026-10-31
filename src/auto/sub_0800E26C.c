struct S0800E26C {
    char f0[14];
    short f14;
    char f16[2];
    short f18;
    char f20[212];
    int f232;
};

extern int sub_080016D0(int a, int b, void **buf, int max);
extern void sub_0800E58C(int a, int b);
extern void sub_0800E640(void);

void sub_0800E26C(void)
{
    void *buf[32];
    unsigned char n;
    unsigned char i;
    int flag;
    struct S0800E26C *p;

    n = sub_080016D0(2, 0, buf, 32);
    flag = 0;
    for (i = 0; i < n; i++) {
        p = buf[i];
        if (p->f232 == 1) {
            sub_0800E58C(p->f14, p->f18);
            flag = 1;
        }
    }
    if (flag == 1)
        sub_0800E640();
}
