int sub_08004A5C(int a, int b);
void sub_08033374(int a, int b);

void sub_0800D550(void *arg)
{
    unsigned char a = ((unsigned char *)arg)[4];
    unsigned char b = ((unsigned char *)arg)[5];
    int ret = sub_08004A5C(a, b);
    if (ret != 0) {
        sub_08033374(ret, 0x23);
    }
}
