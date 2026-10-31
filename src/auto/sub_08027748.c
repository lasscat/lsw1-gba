extern int gUnknown_0300368C[];
extern void sub_08005870(int page, int column, int row, int width, int height, int value);
extern void sub_08006988(int, int, int);
void sub_0800EABC(int a, int b, int c, int d);
extern void sub_080277DC(void);

void sub_08027748(void)
{
    gUnknown_0300368C[2] = 0;
    sub_08005870(0, 0, 0, 0x20, 0x40, 0);
    sub_08005870(1, 0, 0, 0x20, 0x40, 0);
    sub_08005870(2, 0, 0, 0x20, 0x40, 0);
    sub_08006988(0, 0, 0);
    sub_08006988(1, 0, 0);
    sub_08006988(2, 0, 0);
    sub_0800EABC(0, 9, 0, -1);
    gUnknown_0300368C[4] = 0;
    sub_080277DC();
}
