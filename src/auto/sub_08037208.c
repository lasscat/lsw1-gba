extern void sub_080020FC(void *obj, int val);
extern void sub_080365D8(void *arg);

void sub_08037208(void *obj)
{
    if (*(unsigned int *)((unsigned char *)obj + 0xd4) & 0x04000000) {
        sub_080365D8(obj);
    } else {
        *(unsigned char *)((unsigned char *)obj + 0xe1) = 0x2a;
        sub_080020FC(obj, 0);
    }
}
