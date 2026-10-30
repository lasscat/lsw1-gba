extern void sub_0801E458(unsigned char);
extern void sub_0800554C(unsigned short);
extern void sub_08005648(unsigned short);
extern void sub_080053D4(unsigned int, unsigned int);
extern void sub_080054C4(unsigned char);
extern void sub_080054F4(unsigned char);
extern int sub_08005AE8(int, void *, unsigned short, unsigned short, int, int);
extern void sub_080187F8(unsigned short, int);
extern void sub_08031644(int, int);

extern int gUnknown_0300368C[];

void sub_08021A64(void)
{
    int *p;

    sub_0801E458(0);
    sub_0800554C(0);
    sub_08005648(0x80 << 5);
    sub_080053D4(0, *(unsigned int *)0x08048168);
    sub_080054C4(0);
    sub_080054F4(1);
    sub_080054F4(2);
    sub_080054F4(3);
    p = gUnknown_0300368C;
    if (p[0] == 1) {
        sub_08005AE8(0, (void *)0x08E19C84, 0, 0, 0, 0);
    }
    sub_080187F8(0x3f, 2);
    p[5] = 1;
    sub_08031644(0, 0x1e);
    sub_08031644(1, 0x3c);
}
