extern void sub_08033458(void *arg0, int arg1, int arg2, int arg3);

void sub_08035DA8(void *r0)
{
    void *r1;
    r1 = *(void **)((char *)r0 + 0xe8);
    sub_08033458(r1, 0x23, 0, 0);
}
