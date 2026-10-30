void sub_08000F50(void *arg);
void sub_080020FC(void *obj, int val);
void sub_08002138(void *, unsigned int);
void sub_080109C4(void *, int);

void sub_0803957C(void *arg)
{
    sub_08000F50(arg);
    if (((unsigned char *)arg)[0x5c] == 1)
        sub_080109C4(arg, 2);
    sub_08002138(arg, 0x3b);
    sub_080020FC(arg, 2);
}
