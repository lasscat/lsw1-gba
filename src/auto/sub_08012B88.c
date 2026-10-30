extern void sub_080137A0(void *arg0, int arg1, int arg2);
extern void sub_08012C90(void *arg0, void *arg1);

void *sub_08012B88(void *arg0, unsigned int arg1, int arg2)
{
    void *r4;
    unsigned int r6;
    int r7;
    int r2;
    void *r0;
    unsigned int r5;

    r4 = arg0;
    r6 = arg1;
    r7 = arg2;
    r2 = r6 * r7;
    sub_080137A0(r4, 0, r2);
    r0 = 0;
    r5 = 0;
    if (r5 < r6) {
        do {
            sub_08012C90(&r0, r4);
            r4 = (char *)r4 + r7;
            r5 = r5 + 1;
        } while (r5 < r6);
    }
    return r0;
}
