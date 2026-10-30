extern void sub_080020FC(void *obj, int val);

void sub_08011644(void *obj)
{
    if (*(unsigned char *)((unsigned char *)obj + 0xe2) == 0x3b) {
        sub_080020FC(obj, 0x3c);
    } else {
        sub_080020FC(obj, 0x3b);
    }
}
