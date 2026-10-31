typedef struct SpriteLike SpriteLike;
struct SpriteLike {
    int unk0[3];
    int x;
    int y;
};

typedef struct RootLike RootLike;
struct RootLike {
    int unk0;
    SpriteLike *a;
    SpriteLike *b;
    int unkC[3];
    SpriteLike *c;
    SpriteLike *d;
    int unk20[2];
    SpriteLike *e;
};

extern int gUnknown_0300368C[];
extern RootLike *gUnknown_03006AF0;
void sub_080068B4(int, int, int, short);
void sub_08000F78(int *, int, int, int);
void sub_0802D06C(void);

void sub_08027918(void)
{
    gUnknown_0300368C[5] = 0x14;
    sub_08000F78((int *)gUnknown_03006AF0->a, gUnknown_03006AF0->a->x,
        gUnknown_03006AF0->a->y - 0x00A00000, 0x14);
    sub_08000F78((int *)gUnknown_03006AF0->b, gUnknown_03006AF0->b->x,
        gUnknown_03006AF0->a->y - 0x00A00000, 0x14);
    sub_08000F78((int *)gUnknown_03006AF0->c, gUnknown_03006AF0->c->x,
        gUnknown_03006AF0->c->y - 0x00A00000, 0x14);
    sub_08000F78((int *)gUnknown_03006AF0->d, gUnknown_03006AF0->d->x,
        gUnknown_03006AF0->d->y - 0x00A00000, 0x14);
    sub_08000F78((int *)gUnknown_03006AF0->e, gUnknown_03006AF0->e->x,
        gUnknown_03006AF0->e->y - 0x00A00000, 0x14);
    sub_080068B4(0, 0, 0x00A00000, 0x14);
    sub_080068B4(1, 0, 0x00A00000, 0x14);
    sub_0802D06C();
    gUnknown_0300368C[4] = 8;
}
