extern void sub_08001DD4(void *, void *);

void sub_08001E24(void *arg0, void *arg1)
{
    sub_08001DD4(arg0, arg1);
    ((int *)arg1)[0] <<= 16;
    ((int *)arg1)[1] <<= 16;
    ((int *)arg1)[2] <<= 16;
    ((int *)arg1)[3] <<= 16;
}
