extern void sub_08000F78(void *arg0, int arg1, int arg2, int arg3);
extern void sub_080068B4(int a, int b, int c, unsigned short d);
extern void sub_08029308(void *arg0);

struct Obj {
    unsigned char pad[0x96];
    unsigned char b96;
};

struct Group {
    struct Obj *o[26];
};

struct State {
    unsigned char pad[0x14];
    int f14;
};

extern struct State gUnknown_0300368C;
extern struct Group *gUnknown_03006AF4;
extern int gUnknown_0804EC84[];

void sub_08028238(int arg0)
{

    if (arg0 != 0) {
        sub_08029308((void *)0x1e);
        sub_080068B4(2, 0, 0xA00000, gUnknown_0300368C.f14);
        sub_08000F78(gUnknown_03006AF4->o[0], gUnknown_0804EC84[3] << 16, gUnknown_0804EC84[4] << 16, gUnknown_0300368C.f14);
        sub_08000F78(gUnknown_03006AF4->o[1], gUnknown_0804EC84[9] << 16, gUnknown_0804EC84[10] << 16, gUnknown_0300368C.f14);
        sub_08000F78(gUnknown_03006AF4->o[2], gUnknown_0804EC84[15] << 16, gUnknown_0804EC84[16] << 16, gUnknown_0300368C.f14);
        sub_08000F78(gUnknown_03006AF4->o[3], gUnknown_0804EC84[21] << 16, gUnknown_0804EC84[22] << 16, gUnknown_0300368C.f14);
        sub_08000F78(gUnknown_03006AF4->o[4], gUnknown_0804EC84[27] << 16, gUnknown_0804EC84[28] << 16, gUnknown_0300368C.f14);
        sub_08000F78(gUnknown_03006AF4->o[5], gUnknown_0804EC84[33] << 16, gUnknown_0804EC84[34] << 16, gUnknown_0300368C.f14);
        sub_08000F78(gUnknown_03006AF4->o[6], gUnknown_0804EC84[39] << 16, gUnknown_0804EC84[40] << 16, gUnknown_0300368C.f14);
        sub_08000F78(gUnknown_03006AF4->o[15], gUnknown_0804EC84[93] << 16, gUnknown_0804EC84[94] << 16, gUnknown_0300368C.f14);
        sub_08000F78(gUnknown_03006AF4->o[25], (gUnknown_0804EC84[153] - (gUnknown_03006AF4->o[25]->b96 >> 1)) << 16, gUnknown_0804EC84[154] << 16, gUnknown_0300368C.f14);
    } else {
        gUnknown_0300368C.f14 = 0x1e;
        sub_080068B4(2, 0, 0, 0x1e);
        sub_08000F78(gUnknown_03006AF4->o[0], gUnknown_0804EC84[1] << 16, gUnknown_0804EC84[2] << 16, gUnknown_0300368C.f14);
        sub_08000F78(gUnknown_03006AF4->o[1], gUnknown_0804EC84[7] << 16, gUnknown_0804EC84[8] << 16, gUnknown_0300368C.f14);
        sub_08000F78(gUnknown_03006AF4->o[2], gUnknown_0804EC84[13] << 16, gUnknown_0804EC84[14] << 16, gUnknown_0300368C.f14);
        sub_08000F78(gUnknown_03006AF4->o[3], gUnknown_0804EC84[19] << 16, gUnknown_0804EC84[20] << 16, gUnknown_0300368C.f14);
        sub_08000F78(gUnknown_03006AF4->o[4], gUnknown_0804EC84[25] << 16, gUnknown_0804EC84[26] << 16, gUnknown_0300368C.f14);
        sub_08000F78(gUnknown_03006AF4->o[5], gUnknown_0804EC84[31] << 16, gUnknown_0804EC84[32] << 16, gUnknown_0300368C.f14);
        sub_08000F78(gUnknown_03006AF4->o[6], gUnknown_0804EC84[37] << 16, gUnknown_0804EC84[38] << 16, gUnknown_0300368C.f14);
        sub_08000F78(gUnknown_03006AF4->o[15], gUnknown_0804EC84[91] << 16, gUnknown_0804EC84[92] << 16, gUnknown_0300368C.f14);
        sub_08000F78(gUnknown_03006AF4->o[25], gUnknown_0804EC84[151] << 16, gUnknown_0804EC84[152] << 16, gUnknown_0300368C.f14);
    }
}
