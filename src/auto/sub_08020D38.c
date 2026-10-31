struct Sub08020D38Ctx {
    char _00[0x64];
    int unk64;
};

void sub_080186A8(unsigned short a, unsigned short b);
extern void sub_08031644(int, int);
extern int gUnknown_030069DC;
extern unsigned char gUnknown_030069E4;
extern struct Sub08020D38Ctx *gUnknown_030069D8;

void sub_08020D38(void)
{
    int v = gUnknown_030069DC;
    if (v <= 15) {
        unsigned short w = v;
        gUnknown_030069DC = v + 1;
        sub_080186A8(w, 0);
    } else {
        gUnknown_030069E4 = 0;
    }
    sub_08031644(1, gUnknown_030069D8->unk64 * 15 + 30);
}
