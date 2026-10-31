typedef struct {
    int unk0[3];
    int x;
    int y;
} Spr;

typedef struct {
    Spr *p[5];
} Outer;

extern Outer *gUnknown_030069F4;
void sub_08000F78(int *arg0, int arg1, int arg2, int arg3);

void sub_08022718(void)
{
    unsigned int i;
    for (i = 0; i < 3; i++) {
        Spr *s = gUnknown_030069F4->p[i];
        sub_08000F78((int *)s, s->x, s->y + 0x600000, 0x14);
    }
    {
        Spr *s = gUnknown_030069F4->p[3];
        sub_08000F78((int *)s, s->x, s->y + 0x600000, 0x14);
    }
    {
        Spr *s = gUnknown_030069F4->p[4];
        sub_08000F78((int *)s, s->x, s->y + 0x600000, 0x14);
    }
}
