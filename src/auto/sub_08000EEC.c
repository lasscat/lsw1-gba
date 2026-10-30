void sub_08000DA4(void *arg0, int arg1, int arg2);

void sub_08000EEC(void *arg0, int arg1, int arg2)
{
    short *p = (short *)arg0;
    int dx = arg1;
    int dy = arg2;
    int x = p[7] + dx; // 0xE / 2 = 7
    int y = p[9] + dy; // 0x12 / 2 = 9
    sub_08000DA4(arg0, x, y);
}
