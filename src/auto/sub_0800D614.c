extern void sub_08004458(int a, int b);
extern unsigned char gUnknown_0300332C[];

void sub_0800D614(void *arg)
{
    unsigned char *p = arg;
    unsigned char val = gUnknown_0300332C[0xBB];
    if (val == p[4] + 0x2C) {
        sub_08004458(0, p[5]);
    } else {
        sub_08004458(0, p[6]);
    }
}
