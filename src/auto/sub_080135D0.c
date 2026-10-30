extern void *sub_08013538(int);
extern void sub_080137A0(void *arg0, int arg1, int arg2);

void *sub_080135D0(int arg0)
{
    int size = (arg0 + 15) & -16;
    void *r = sub_08013538(size);
    if (r != 0)
        sub_080137A0(r, 0, size);
    return r;
}
