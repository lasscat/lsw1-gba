void sub_08000F78(int *arg0, int arg1, int arg2, int arg3);
struct U080226AC { int *v[5]; };
extern struct U080226AC *gUnknown_030069F4;

void sub_080226AC(void)
{
    int *p;
    unsigned int i;

    for (i = 0; i <= 2; i++) {
        p = gUnknown_030069F4->v[i];
        sub_08000F78(p, p[3], p[4] + 0xFFA00000, 0x14);
    }
    p = gUnknown_030069F4->v[3];
    sub_08000F78(p, p[3], p[4] + 0xFFA00000, 0x14);
    p = gUnknown_030069F4->v[4];
    sub_08000F78(p, p[3], p[4] + 0xFFA00000, 0x14);
}
