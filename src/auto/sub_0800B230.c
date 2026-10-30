int sub_08004A5C(unsigned char, unsigned char);
void sub_080393C4(int, unsigned char);

void sub_0800B230(void *r0)
{
    unsigned char *r4 = r0;
    int ret = sub_08004A5C(r4[4], r4[5]);
    sub_080393C4(ret, r4[6]);
}
