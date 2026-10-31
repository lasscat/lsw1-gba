extern void sub_08005870(int page, int column, int row, int width, int height, int value);
extern void *sub_0801D0AC(const char *index);
extern int sub_0800EDD8(int start_x, int place_x, int line_y, int place_y, unsigned char *text, int mode);
extern void sub_0800F454(int value);
extern int gUnknown_030069C0[];

void sub_08020814(void)
{
    int text_x;
    unsigned char *text;
    int line_y;
    int *p;
    int i;

    text_x = gUnknown_030069C0[4];
    text = sub_0801D0AC((const char *)0x45);
    sub_08005870(1, 0x15, 5, 4, 0xc, 0);
    line_y = 0x32;
    p = &gUnknown_030069C0[2];
    i = 1;
    do {
        sub_0800F454(*p++);
        text_x = sub_0800EDD8(text_x + 1, 0xb4, line_y, 0x64, text, 1);
        line_y += 0x12;
        i--;
    } while (i >= 0);
}
