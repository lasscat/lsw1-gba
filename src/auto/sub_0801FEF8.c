extern void *sub_0801D0AC(const char *a);
extern int sub_0800EF10(int a, int b, int c, const char *text, int mode);
extern unsigned char gUnknown_03006DB6;

void sub_0801FEF8(void)
{
    int x = 1;
    int i = 0;
    unsigned char *flag = &gUnknown_03006DB6;
    int y = 10;
    const char *text;

    do {
        text = sub_0801D0AC((const char *)(i + 0x3c));
        if (i == 3 && (*flag & 2) != 0)
            text = sub_0801D0AC((const char *)0x41);
        if (i == 4 && (*flag & 0x10) != 0)
            text = sub_0801D0AC((const char *)0x42);
        x = sub_0800EF10(x, 0x3c, y, text, 0);
        y += 12;
        i++;
    } while (i <= 4);
}
