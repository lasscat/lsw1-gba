void sub_08000F78(int *arg0, int arg1, int arg2, int arg3);
extern int sub_0802C9D4(int);
int sub_0802CA5C(unsigned int r0);

struct S0801F6F0 {
    int *a[15];
    int *b[15];
    int *c[4];
    int *p88;
    signed char b8c;
    char pad8d[3];
    int *p90;
    unsigned char b94;
    unsigned char cnt95;
};

extern struct S0801F6F0 *gUnknown_0300699C;

static inline void draw(int *p)
{
    sub_08000F78(p, p[3], p[4] + 0xFF600000, 0x14);
}
static inline void draw2(struct S0801F6F0 *s, unsigned int i)
{
    sub_08000F78(s->b[i], s->a[i][3], s->a[i][4] + 0xFF600000, 0x14);
}

void sub_0801F6F0(void)
{
    unsigned int i;

    for (i = 0; i <= 14; i++) {
        int *p = gUnknown_0300699C->a[i];
        draw(p);
        if (sub_0802C9D4(i) != 0 && sub_0802CA5C(i) == 0)
            draw2(gUnknown_0300699C, i);
    }
    for (i = 0; i < gUnknown_0300699C->cnt95; i++)
        draw(gUnknown_0300699C->c[i]);
    draw(gUnknown_0300699C->p90);
}
