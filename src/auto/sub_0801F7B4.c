void sub_08005674(int arg0);
void sub_08000F78(int *arg0, int arg1, int arg2, int arg3);
struct Main {
    int *a[15];
    int *b[15];
    int *c[6];
    int *d;
    unsigned char pad94;
    unsigned char cnt95;
};
extern struct Main *gUnknown_0300699C;
void sub_0801F7B4(void)
{
    unsigned int i;
    int *q;
    sub_08005674(2);
    q = gUnknown_0300699C->c[4];
    q[22] &= -2;
    for (i = 0; i <= 14; i++)
    {
        sub_08000F78(gUnknown_0300699C->a[i], gUnknown_0300699C->a[i][3], gUnknown_0300699C->a[i][4] + 0x00A00000, 0x14);
        if (gUnknown_0300699C->b[i] != 0)
            sub_08000F78(gUnknown_0300699C->b[i], gUnknown_0300699C->a[i][3], gUnknown_0300699C->a[i][4] + 0x00A00000, 0x14);
    }
    for (i = 0; i <= gUnknown_0300699C->cnt95; i++)
    {
        if (gUnknown_0300699C->c[i] != 0)
            sub_08000F78(gUnknown_0300699C->c[i], gUnknown_0300699C->c[i][3], gUnknown_0300699C->c[i][4] + 0x00A00000, 0x14);
    }
    sub_08000F78(gUnknown_0300699C->d, gUnknown_0300699C->d[3], gUnknown_0300699C->d[4] + 0x00A00000, 0x14);
}
