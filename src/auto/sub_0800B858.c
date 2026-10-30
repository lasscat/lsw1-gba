
extern int sub_08004A5C(unsigned char a, unsigned char b);
extern int sub_08002138(void *obj, unsigned int arg);

void sub_0800B858(void *arg)
{
    unsigned char a = ((unsigned char *)arg)[4];
    unsigned char b = ((unsigned char *)arg)[5];
    void *obj = (void *)sub_08004A5C(a, b);
    if (obj) {
        sub_08002138(obj, 4);
    }
}
