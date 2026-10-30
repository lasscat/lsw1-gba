extern unsigned int gUnknown_0300332C;
extern unsigned int gUnknown_0300340C;
extern void sub_080020FC(void *obj, int val);
extern void sub_08010FC8(void);
extern void sub_0801C19C(unsigned int arg);

void sub_0802B7C8(void)
{
    unsigned int *p = &gUnknown_0300332C;
    sub_0801C19C(p[0x2A]);
    sub_0801C19C(p[0x28]);
    sub_08010FC8();
    sub_080020FC((void *)gUnknown_0300340C, 2);
}
