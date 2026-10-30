extern void sub_080020FC(void *obj, int val);

void sub_0803683C(void *obj)
{
    ((unsigned char *)obj)[0xe1] = 0x33;
    sub_080020FC(obj, 0);
}
