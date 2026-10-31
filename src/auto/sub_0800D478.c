void sub_08004A5C(int, int);
void sub_0803ED14(void);

void sub_0800D478(void *arg)
{
    unsigned char a = ((unsigned char *)arg)[4];
    unsigned char b = ((unsigned char *)arg)[5];
    sub_08004A5C(a, b);
    sub_0803ED14();
}
