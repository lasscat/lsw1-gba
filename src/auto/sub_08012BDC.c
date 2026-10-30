extern void *sub_08012C60(void *arg0);
extern void sub_08012C90(void *arg0, void *arg1);
extern void sub_080137A0(void *arg0, int arg1, int arg2);

void *sub_08012BDC(void *arg0, void *arg1, int arg2)
{
    void *r4;

    if (*(int *)arg0 == 0) {
        return 0;
    }
    r4 = sub_08012C60(arg0);
    sub_080137A0(r4, 0, arg2);
    sub_08012C90(arg1, r4);
    return r4;
}
