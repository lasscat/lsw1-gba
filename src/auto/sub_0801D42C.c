extern void *gUnknown_03006718[];
extern void *sub_0801D35C(void *r0);

int sub_0801D42C(unsigned char **arg0, int arg1)
{
    unsigned char count = 0;
    void **base = gUnknown_03006718;
    void **dst = base + arg1;

    do {
        void *p = sub_0801D35C(arg0);
        *dst++ = p;
        ((unsigned char *)p)[0x5c] = (unsigned char)arg1;
        count++;
        arg1++;
    } while (**arg0 != 0);
    return count;
}
