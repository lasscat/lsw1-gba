typedef struct SpriteLike SpriteLike;
struct SpriteLike {
    int unk0[3];
    int x;
    int y;
};

typedef struct RootLike RootLike;
struct RootLike {
    int unk0[2];
    SpriteLike *a;
    SpriteLike *b;
    SpriteLike *c;
    SpriteLike *d;
    SpriteLike *e;
};

extern int gUnknown_0300368C[];
extern RootLike *gUnknown_03006AEC;
void sub_080068B4(int, int, int, short);
void sub_08000F78(int *, int, int, int);

void sub_080267B0(void)
{
    gUnknown_0300368C[5] = 0x14;
    sub_080068B4(0, 0, 0, 0x14);
    sub_080068B4(1, 0, 0, 0x14);
    sub_08000F78((int *)gUnknown_03006AEC->a, gUnknown_03006AEC->a->x,
        gUnknown_03006AEC->a->y + 0x00A00000, 0x14);
    sub_08000F78((int *)gUnknown_03006AEC->b, gUnknown_03006AEC->b->x,
        gUnknown_03006AEC->b->y + 0x00A00000, 0x14);
    sub_08000F78((int *)gUnknown_03006AEC->d, gUnknown_03006AEC->d->x,
        gUnknown_03006AEC->d->y + 0x00A00000, 0x14);
    sub_08000F78((int *)gUnknown_03006AEC->e, gUnknown_03006AEC->e->x,
        gUnknown_03006AEC->e->y + 0x00A00000, 0x14);
    sub_08000F78((int *)gUnknown_03006AEC->c, gUnknown_03006AEC->c->x,
        gUnknown_03006AEC->c->y + 0x00A00000, 0x14);
}
