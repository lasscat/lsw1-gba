extern unsigned int sub_08004A5C(unsigned char, unsigned char);
extern void sub_08040664(unsigned int, int, unsigned char, int);

void sub_0800D008(void *r0)
{
    unsigned char *r4 = r0;
    unsigned int ret = sub_08004A5C(r4[4], r4[5]);
    if (ret) {
        sub_08040664(ret, 0, r4[6], 1);
    }
}
