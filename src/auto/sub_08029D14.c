extern void sub_080053D4(unsigned int a, unsigned int b);
extern int sub_08005B90(int a, void *b, unsigned short c, unsigned short d);
extern void sub_08029D70(void);

struct S6AFC {
    unsigned int a;
    unsigned int b;
    unsigned short c;
    unsigned short d;
};
extern struct S6AFC gUnknown_03006AFC;

void sub_08029D14(void)
{
    sub_080053D4(3, *(unsigned int *)0x0804F4E4);
    gUnknown_03006AFC.a = sub_08005B90(3, (void *)0x08E1BC9C, 0, 0);
    gUnknown_03006AFC.c = 0x80 << 1;
    gUnknown_03006AFC.d = 0;
    gUnknown_03006AFC.b = 1;
    sub_08029D70();
}
