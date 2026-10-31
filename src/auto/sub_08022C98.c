void sub_08000F78(int *arg0, int arg1, int arg2, int arg3);
void sub_08022D18(void *arg0);
struct U08022C98 { int unk0; int *v[7]; int *a; int *b; };
extern struct U08022C98 *gUnknown_030069F8;

void sub_08022C98(void)
{
    int *p;
    unsigned int i;

    for (i = 0; i <= 6; i++) {
        p = gUnknown_030069F8->v[i];
        sub_08000F78(p, p[3], p[4] + 0x00A00000, 0x14);
        gUnknown_030069F8->v[i][24] = (int)sub_08022D18;
    }
    p = gUnknown_030069F8->a;
    sub_08000F78(p, p[3], p[4] + 0x00A80000, 0x14);
    p = gUnknown_030069F8->b;
    sub_08000F78(p, p[3], p[4] + 0x00A80000, 0x14);
}
