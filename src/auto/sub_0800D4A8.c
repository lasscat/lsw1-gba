int sub_08004A5C(int a, int b);
void sub_0803ED70(void);

void sub_0800D4A8(void *arg)
{
    unsigned char *p = (unsigned char *)arg;
    sub_08004A5C(p[4], p[5]);
    sub_0803ED70();
}
