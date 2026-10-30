extern unsigned int sub_08004A5C(unsigned char, unsigned char);
extern void sub_08002138(void *, unsigned int);

void sub_0800B88C(void *arg)
{
    unsigned char a = *(unsigned char *)((unsigned char *)arg + 4);
    unsigned char b = *(unsigned char *)((unsigned char *)arg + 5);
    void *r4 = (void *)sub_08004A5C(a, b);
    if (r4 != 0) {
        sub_08002138(r4, 5);
    }
}
