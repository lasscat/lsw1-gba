extern unsigned int gUnknown_0300340C;
extern void sub_08041994(void *arg);

void sub_080418F8(void *arg)
{
    unsigned short *p;
    unsigned int base;
    unsigned short a;
    unsigned short b;

    base = gUnknown_0300340C;
    p = (unsigned short *)(base + 0xec);
    a = *p;
    b = *(unsigned short *)((char *)arg + 8);
    if (a == b)
        return;
    sub_08041994(arg);
}
