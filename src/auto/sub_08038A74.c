extern void *gUnknown_03007014;

void sub_08037548(void *arg0, int arg1, void *arg2, int arg3);
void sub_0802A758(void *arg0, int arg1);
void sub_080013F4(void *arg0, void *arg1, int arg2, void *arg3);

void sub_08038A74(void *arg)
{
    void *r4 = arg;
    void *r2 = gUnknown_03007014;
    sub_08037548(r4, 0, r2, 0);
    sub_0802A758(r4, 1);
    sub_080013F4(r4 + 0x24, (void *)0x80000000, *(unsigned char *)(r4 + 0x5f), *(void **)(r4 + 8));
}
