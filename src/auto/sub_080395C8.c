void sub_080109C4(void *, int);
void sub_080020FC(void *obj, int val);

void sub_080395C8(void *arg)
{
    if (((unsigned char *)arg)[0x5c] == 1) {
        if (((unsigned char *)arg)[0xf8] != 2 && ((((unsigned int *)arg)[0x16] & 0x40000) != 0)) {
            sub_080109C4(arg, 2);
            sub_080020FC(arg, 2);
        }
    } else {
        sub_080020FC(arg, 2);
    }
}
