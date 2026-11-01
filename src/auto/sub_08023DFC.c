extern unsigned char gUnknown_03006B1C[];
struct Ui {
    char pad0[0x14];
    void *w14;
    void *w18;
    void *w1c;
    void *w20;
    void *w24;
    char pad28[0x10];
    int i38;
    char pad3c[4];
    int i40;
};
extern struct Ui *gUnknown_030069FC;
extern int gUnknown_080716D0[];
extern const char *gUnknown_0804CBF0[];

void sub_0800EABC(int a, int b, int c, int d);
void sub_0800F454();
void sub_0800F47C(int a);
void *sub_0801D0AC(const char *a);
void sub_0801D47C(void *r0, void *r1);
void sub_0801D514(void *arg0, int arg1, short arg2, short arg3, int flags);
int sub_0802CB20(int arg0);

void sub_08023DFC(void)
{
    int idx;
    void *s;

    idx = gUnknown_080716D0[gUnknown_03006B1C[0x291]] + gUnknown_030069FC->i40 + gUnknown_030069FC->i38;
    sub_0800EABC(0, 9, 0, 0);
    s = sub_0801D0AC(gUnknown_0804CBF0[(gUnknown_03006B1C + 0x3DC)[idx]]);
    sub_0801D47C(gUnknown_030069FC->w14, s);
    sub_0801D514(gUnknown_030069FC->w14, (int)s, 0x3c, 0x88, 1);
    sub_0802CB20(idx);
    sub_0800F454();
    sub_0800F47C(5);
    s = sub_0801D0AC((const char *)0x46);
    sub_0801D47C(gUnknown_030069FC->w1c, s);
    sub_0801D514(gUnknown_030069FC->w1c, (int)s, 0x93, 0x88, 1);
    sub_0800F454(*(unsigned short *)(gUnknown_03006B1C + 0x422 + idx * 2));
    s = sub_0801D0AC((const char *)0x45);
    sub_0801D47C(gUnknown_030069FC->w18, s);
    sub_0801D514(gUnknown_030069FC->w18, (int)s, 0x75, 0x88, 1);
    sub_0800F454(*(unsigned short *)(gUnknown_03006B1C + 0x406 + idx * 2));
    s = sub_0801D0AC((const char *)0x45);
    sub_0801D47C(gUnknown_030069FC->w20, s);
    sub_0801D514(gUnknown_030069FC->w20, (int)s, 0xb2, 0x88, 1);
    sub_0800F454(*(unsigned short *)(gUnknown_03006B1C + 0x3EA + idx * 2));
    s = sub_0801D0AC((const char *)0x45);
    sub_0801D47C(gUnknown_030069FC->w24, s);
    sub_0801D514(gUnknown_030069FC->w24, (int)s, 0xd2, 0x88, 1);
}
