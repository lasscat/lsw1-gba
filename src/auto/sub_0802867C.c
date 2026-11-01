typedef struct { int tag; int x; int y; int pad[3]; } Ent;
typedef struct { unsigned char pad[0x96]; unsigned char w; } Obj;
typedef struct { int pad[5]; int s; } St;
extern St gUnknown_0300368C;
extern Obj **gUnknown_03006AF4;
extern Ent gUnknown_0804EC84[];
void sub_08000F78(int *arg0, int arg1, int arg2, int arg3);
void sub_08028448(int);
void sub_08028238(int);

void sub_0802867C(void)
{
    int a7, b7;
    int *p7;
    gUnknown_0300368C.s = 30;
    sub_08028448(0);
    sub_08028238(0);
    sub_08000F78((int *)gUnknown_03006AF4[0], gUnknown_0804EC84[0].x << 16, gUnknown_0804EC84[0].y << 16, gUnknown_0300368C.s);
    sub_08000F78((int *)gUnknown_03006AF4[1], gUnknown_0804EC84[1].x << 16, gUnknown_0804EC84[1].y << 16, gUnknown_0300368C.s);
    sub_08000F78((int *)gUnknown_03006AF4[2], gUnknown_0804EC84[2].x << 16, gUnknown_0804EC84[2].y << 16, gUnknown_0300368C.s);
    sub_08000F78((int *)gUnknown_03006AF4[3], gUnknown_0804EC84[3].x << 16, gUnknown_0804EC84[3].y << 16, gUnknown_0300368C.s);
    sub_08000F78((int *)gUnknown_03006AF4[4], gUnknown_0804EC84[4].x << 16, gUnknown_0804EC84[4].y << 16, gUnknown_0300368C.s);
    sub_08000F78((int *)gUnknown_03006AF4[5], gUnknown_0804EC84[5].x << 16, gUnknown_0804EC84[5].y << 16, gUnknown_0300368C.s);
    p7 = (int *)gUnknown_03006AF4[7];
    a7 = gUnknown_0804EC84[7].x << 16;
    b7 = gUnknown_0804EC84[7].y << 16;
    sub_08000F78(p7, a7, b7, gUnknown_0300368C.s);
    sub_08000F78((int *)gUnknown_03006AF4[8], gUnknown_0804EC84[8].x << 16, gUnknown_0804EC84[8].y << 16, gUnknown_0300368C.s);
    sub_08000F78((int *)gUnknown_03006AF4[9], gUnknown_0804EC84[9].x << 16, gUnknown_0804EC84[9].y << 16, gUnknown_0300368C.s);
    sub_08000F78((int *)gUnknown_03006AF4[10], gUnknown_0804EC84[10].x << 16, gUnknown_0804EC84[10].y << 16, gUnknown_0300368C.s);
    sub_08000F78((int *)gUnknown_03006AF4[11], a7, b7, gUnknown_0300368C.s);
    sub_08000F78((int *)gUnknown_03006AF4[12], gUnknown_0804EC84[12].x << 16, gUnknown_0804EC84[12].y << 16, gUnknown_0300368C.s);
    sub_08000F78((int *)gUnknown_03006AF4[13], gUnknown_0804EC84[13].x << 16, gUnknown_0804EC84[13].y << 16, gUnknown_0300368C.s);
    sub_08000F78((int *)gUnknown_03006AF4[14], gUnknown_0804EC84[14].x << 16, gUnknown_0804EC84[14].y << 16, gUnknown_0300368C.s);
    sub_08000F78((int *)gUnknown_03006AF4[15], gUnknown_0804EC84[15].x << 16, gUnknown_0804EC84[15].y << 16, gUnknown_0300368C.s);
    sub_08000F78((int *)gUnknown_03006AF4[16], gUnknown_0804EC84[16].x << 16, gUnknown_0804EC84[16].y << 16, gUnknown_0300368C.s);
    sub_08000F78((int *)gUnknown_03006AF4[17], (gUnknown_0804EC84[17].x - (gUnknown_03006AF4[17]->w >> 1)) << 16, gUnknown_0804EC84[17].y << 16, gUnknown_0300368C.s);
    sub_08000F78((int *)gUnknown_03006AF4[18], (gUnknown_0804EC84[18].x - (gUnknown_03006AF4[18]->w >> 1)) << 16, gUnknown_0804EC84[18].y << 16, gUnknown_0300368C.s);
    sub_08000F78((int *)gUnknown_03006AF4[19], (gUnknown_0804EC84[19].x - (gUnknown_03006AF4[19]->w >> 1)) << 16, gUnknown_0804EC84[19].y << 16, gUnknown_0300368C.s);
    sub_08000F78((int *)gUnknown_03006AF4[20], (gUnknown_0804EC84[20].x - (gUnknown_03006AF4[20]->w >> 1)) << 16, gUnknown_0804EC84[20].y << 16, gUnknown_0300368C.s);
    sub_08000F78((int *)gUnknown_03006AF4[21], (gUnknown_0804EC84[21].x - (gUnknown_03006AF4[21]->w >> 1)) << 16, gUnknown_0804EC84[21].y << 16, gUnknown_0300368C.s);
    sub_08000F78((int *)gUnknown_03006AF4[22], (gUnknown_0804EC84[22].x - (gUnknown_03006AF4[22]->w >> 1)) << 16, gUnknown_0804EC84[22].y << 16, gUnknown_0300368C.s);
    sub_08000F78((int *)gUnknown_03006AF4[23], (gUnknown_0804EC84[23].x - (gUnknown_03006AF4[23]->w >> 1)) << 16, gUnknown_0804EC84[23].y << 16, gUnknown_0300368C.s);
    sub_08000F78((int *)gUnknown_03006AF4[24], (gUnknown_0804EC84[24].x - (gUnknown_03006AF4[24]->w >> 1)) << 16, gUnknown_0804EC84[24].y << 16, gUnknown_0300368C.s);
    sub_08000F78((int *)gUnknown_03006AF4[25], (gUnknown_0804EC84[25].x - (gUnknown_03006AF4[25]->w >> 1)) << 16, gUnknown_0804EC84[25].y << 16, gUnknown_0300368C.s);
    sub_08000F78((int *)gUnknown_03006AF4[26], (gUnknown_0804EC84[26].x - (gUnknown_03006AF4[26]->w >> 1)) << 16, gUnknown_0804EC84[26].y << 16, gUnknown_0300368C.s);
}
