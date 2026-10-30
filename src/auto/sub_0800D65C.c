extern void sub_08004458(int a, int b);
extern unsigned short gUnknown_030024EC[];

void sub_0800D65C(void *arg)
{
    unsigned char *p = arg;
    unsigned short val = gUnknown_030024EC[4];
    if (val > p[4]) {
        sub_08004458(0, p[5]);
    } else {
        sub_08004458(0, p[6]);
    }
}
