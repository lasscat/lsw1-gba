void sub_080136AC(void *arg);

extern unsigned int gUnknown_03004E54;
extern unsigned int gUnknown_03004E58;
extern unsigned int gUnknown_03004E5C;
extern unsigned int gUnknown_03004E60;
extern unsigned int gUnknown_03004E64;
extern unsigned int gUnknown_03004E68;
extern unsigned int gUnknown_03004E6C;
extern unsigned int gUnknown_03004E70;

void sub_0801A5A4(void)
{
    if (gUnknown_03004E54 != 0) {
        sub_080136AC((void *)gUnknown_03004E54);
        gUnknown_03004E54 = 0;
    }
    if (gUnknown_03004E58 != 0) {
        sub_080136AC((void *)gUnknown_03004E58);
        gUnknown_03004E58 = 0;
    }
    if (gUnknown_03004E5C != 0) {
        sub_080136AC((void *)gUnknown_03004E5C);
        gUnknown_03004E5C = 0;
    }
    if (gUnknown_03004E60 != 0) {
        sub_080136AC((void *)gUnknown_03004E60);
        gUnknown_03004E60 = 0;
    }
    if (gUnknown_03004E64 != 0) {
        gUnknown_03004E64 -= 4;
        sub_080136AC((void *)gUnknown_03004E64);
        gUnknown_03004E64 = 0;
    }
    if (gUnknown_03004E68 != 0) {
        gUnknown_03004E68 -= 4;
        sub_080136AC((void *)gUnknown_03004E68);
        gUnknown_03004E68 = 0;
    }
    if (gUnknown_03004E6C != 0) {
        gUnknown_03004E6C -= 4;
        sub_080136AC((void *)gUnknown_03004E6C);
        gUnknown_03004E6C = 0;
    }
    if (gUnknown_03004E70 != 0) {
        gUnknown_03004E70 -= 4;
        sub_080136AC((void *)gUnknown_03004E70);
    }
}
