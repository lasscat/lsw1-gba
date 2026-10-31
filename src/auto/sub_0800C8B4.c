extern void *gUnknown_03002BF8;
extern unsigned short sub_080049E0(unsigned char);
extern unsigned int sub_08004A5C(unsigned char, unsigned char);
extern void sub_08002138(void *, unsigned int);

void sub_0800C8B4(void *arg0)
{
    unsigned char i;
    for (i = 2; i < *(unsigned short *)gUnknown_03002BF8; i++) {
        if (i == ((unsigned char *)arg0)[4])
            continue;
        if (i == ((unsigned char *)arg0)[5])
            continue;
        if (i == ((unsigned char *)arg0)[6])
            continue;
        {
            unsigned short n = sub_080049E0(i);
            unsigned char j;
            for (j = 0; j < n; j++) {
                void *obj = (void *)sub_08004A5C(i, j);
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
}
