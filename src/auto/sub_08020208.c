extern void sub_0800EABC(int a, int b, int c, int d);
extern void sub_0800E9B4(unsigned int a);
extern void *sub_0801D0AC(const char *index);
extern int sub_0800EDD8(int start_x, int place_x, int line_y, int place_y, unsigned char *text, int mode);
extern unsigned int gUnknown_0804C91C;
extern unsigned int gUnknown_0804C920;

void sub_08020208(void)
{
    int x1;
    int x2;
    int *p;
    int i;

    sub_0800EABC(2, 9, 0, 0);
    x1 = 1;
    x2 = 1;
    sub_0800E9B4(gUnknown_0804C91C);
    i = 0;
    p = &x1;
    do {
        *p = sub_0800EDD8(*p, 0x47, i * 8, 0xE6, sub_0801D0AC((const char *)(i + 0x58)), 0);
        i++;
    } while (i <= 0x1A);
    sub_0800E9B4(gUnknown_0804C920);
    if (i <= 0x36) {
        p = &x2;
        do {
            *p = sub_0800EDD8(*p, 0x47, i * 8, 0xE6, sub_0801D0AC((const char *)(i + 0x58)), 0);
            i++;
        } while (i <= 0x36);
    }
}
