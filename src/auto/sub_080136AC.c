// unknown

void sub_08013A54(void *, void *);
void sub_08013B28(void *, void *);
void sub_08013B7C(void *, void *);

void sub_080136AC(void *arg)
{
    void *r4;
    void *r5;

    r4 = (void *)((char *)arg - 0x10);
    r5 = *(void **)((char *)r4 + 8);
    sub_08013A54(r4, r5);
    sub_08013B28(r4, r5);
    sub_08013B7C(r4, r5);
}
