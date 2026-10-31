typedef struct Sprite Sprite;
struct Sprite {
    int unk0[3];
    int x;
    int y;
};

typedef struct Root Root;
struct Root {
    int f00;
    Sprite *f04;
    Sprite *f08;
    int f0C;
    int f10;
    int f14;
    Sprite *f18;
    Sprite *f1C;
    int f20;
    int f24;
    Sprite *f28;
};

extern int gUnknown_0300368C[];
extern Root *gUnknown_03006AF0;
void sub_080068B4(int, int, int, short);
void sub_08000F78(int *, int, int, int);

void sub_080279C8(void)
{
    gUnknown_0300368C[5] = 0x14;
    sub_080068B4(0, 0, 0, 0x14);
    sub_080068B4(1, 0, 0, 0x14);
    sub_08000F78((int *)gUnknown_03006AF0->f04, gUnknown_03006AF0->f04->x,
        gUnknown_03006AF0->f04->y + 0x00A00000, 0x14);
    sub_08000F78((int *)gUnknown_03006AF0->f08, gUnknown_03006AF0->f08->x,
        gUnknown_03006AF0->f08->y + 0x00A00000, 0x14);
    sub_08000F78((int *)gUnknown_03006AF0->f18, gUnknown_03006AF0->f18->x,
        gUnknown_03006AF0->f18->y + 0x00A00000, 0x14);
    sub_08000F78((int *)gUnknown_03006AF0->f1C, gUnknown_03006AF0->f1C->x,
        gUnknown_03006AF0->f1C->y + 0x00A00000, 0x14);
    sub_08000F78((int *)gUnknown_03006AF0->f28, gUnknown_03006AF0->f28->x,
        gUnknown_03006AF0->f28->y + 0x00A00000, 0x14);
    gUnknown_0300368C[4] = 10;
}
