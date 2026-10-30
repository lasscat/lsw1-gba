extern void sub_08000F50(void *);
extern void sub_080109C4(void *, int);

void sub_08039624(void *arg)
{
    void *tmp = arg;
    sub_08000F50(arg);
    sub_080109C4(tmp, 2);
}
