extern int sub_0800499C(unsigned char);
extern void sub_080044A8(unsigned char, unsigned int);

void sub_0800CA54(void *arg0)
{
    unsigned char r4 = *(unsigned char *)((unsigned char *)arg0 + 4);
    if (sub_0800499C(r4)) {
        sub_080044A8(r4, 1);
    }
}
