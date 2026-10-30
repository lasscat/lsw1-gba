extern int sub_0800499C(unsigned char);
extern unsigned short sub_080049E0(unsigned char);
extern unsigned int sub_08004A5C(unsigned char, unsigned char);

void sub_0800C95C(void *arg0)
{
    unsigned char v = *(unsigned char *)((unsigned char *)arg0 + 4);
    if (sub_0800499C(v)) {
        unsigned short n = sub_080049E0(v);
        unsigned char i;
        for (i = 0; i < n; i++)
            sub_08004A5C(v, i);
    }
}
