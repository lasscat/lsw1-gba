extern int gUnknown_030069DC;
extern unsigned char gUnknown_030069E8;
int sub_080186A8(int a, int b);

void sub_08020D94(void)
{
    int v = gUnknown_030069DC;
    if (v >= 0) {
        unsigned short w = v;
        gUnknown_030069DC--;
        sub_080186A8(w, 0);
    } else {
        gUnknown_030069E8 = 0;
        gUnknown_030069DC = 0;
    }
}
