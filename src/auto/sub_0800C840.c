extern int sub_0800499C(unsigned char);
extern unsigned short sub_080049E0(unsigned char);
extern unsigned int sub_08004A5C(unsigned char, unsigned char);
extern void sub_08002138(void *, unsigned int);

void sub_0800C840(void *arg0)
{
    unsigned char v = *(unsigned char *)((unsigned char *)arg0 + 4);
    if (sub_0800499C(v)) {
        unsigned short n = sub_080049E0(v);
        unsigned char i;
        for (i = 0; i < n; i++) {
            void *obj = (void *)sub_08004A5C(v, i);
            if (obj != 0) {
                if (*(void **)((char *)obj + 0x60) == 0) {
                    *(unsigned int *)((char *)obj + 0x58) |= 2;
                } else {
                    sub_08002138(obj, 1);
                    *(unsigned int *)((char *)obj + 0x58) |= 0x28;
                }
            }
        }
    }
}
