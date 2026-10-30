extern int sub_0802C9D4(int);
extern int sub_0802C98C(int, int);
extern unsigned char gUnknown_03006B1C[];
extern unsigned int gUnknown_03006B14;

void sub_0800DB9C(void *arg)
{
    unsigned char *p = arg;
    if (sub_0802C9D4(p[4]) != 0)
        return;
    gUnknown_03006B1C[0x467] = p[4];
    sub_0802C98C(p[4], 1);
    gUnknown_03006B14 |= 0x80;
}
