extern void sub_080020FC(void *obj, int val);

void sub_080371D8(void *obj)
{
    *(unsigned char *)((unsigned char *)obj + 0xe1) = 0x28;
    sub_080020FC(obj, 0);
}
