void *sub_0802D28C(int arg0, int arg1, int arg2, int arg3);
void sub_08000C7C(void *arg0, void *arg1, void *arg2, int arg3);
void sub_08009F98(int a, int b, int c);
void sub_08000F78(int *arg0, int arg1, int arg2, int arg3);

struct SInner {
    int unk0;
    int unk4;
    int unk8;
    int x;
    int y;
    int unk14[17];
    int flags;
};

struct SOuter {
    int unk0[14];
    int u38;
};

extern struct SOuter *gUnknown_030072F0;
extern char gUnknown_03000148[];
extern char gUnknown_08E072E0[];
extern char gUnknown_08DB44C4[];

void sub_0803FAF8(void)
{
    struct SInner *a;
    struct SInner *b;
    a = sub_0802D28C(0x31, 0xC9, (int)gUnknown_03000148, 0);
    gUnknown_030072F0->u38 = (int)a;
    a->flags |= 0x10;
    sub_08000C7C((void *)gUnknown_030072F0->u38, gUnknown_03000148, gUnknown_08E072E0, 0);
    sub_08009F98((int)gUnknown_08DB44C4, 0, 0x10);
    b = (struct SInner *)gUnknown_030072F0->u38;
    sub_08000F78((int *)b, b->x, b->y - 0xA00000, 0x14);
}
