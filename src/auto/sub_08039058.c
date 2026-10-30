extern unsigned int gUnknown_03007014;

void sub_08037548(void *arg, int b, unsigned int c, int d);
void sub_08000D00(void *arg0, int arg1);
void sub_08000F50(void *arg);

void sub_08039058(void *arg0)
{
    sub_08037548(arg0, 2, gUnknown_03007014, 0);
    sub_08000D00(arg0, 0);
    ((unsigned int *)arg0)[0x58 / 4] &= -0x11;
    sub_08000F50(arg0);
}
