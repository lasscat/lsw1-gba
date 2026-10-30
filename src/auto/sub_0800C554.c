extern unsigned int sub_08004A5C(unsigned char, unsigned char);
extern void sub_08038128(void *, unsigned int, unsigned char);
extern unsigned int gUnknown_0300340C;

void sub_0800C554(void *arg)
{
    unsigned char a = ((unsigned char *)arg)[4];
    unsigned char b = ((unsigned char *)arg)[5];
    void *r = (void *)sub_08004A5C(a, b);
    if (r != 0) {
        if (*(short *)((unsigned char *)r + 0xd8) != 0) {
            sub_08038128(r, gUnknown_0300340C, ((unsigned char *)arg)[6]);
        }
    }
}
