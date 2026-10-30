extern int gUnknown_030049E8;
extern void *gUnknown_030049D4;
extern void *gUnknown_03002F30;
extern int gUnknown_03002F2C;
extern int gUnknown_030049D0;
extern int gUnknown_030049EC;
extern int *gUnknown_030034A4;
extern unsigned int gUnknown_03006B18;

extern void sub_0800A040(void);
extern void CpuFastSet(void *src, void *dst, unsigned int mode);
extern void sub_0800A404(int a0, int a1, int a2, int a3, int a4, void *a5);
extern void sub_080188B8(void);
extern void sub_080125F8(void);

void sub_08018B4C(void)
{
    int a = gUnknown_030049E8;
    int size;
    int x;
    int n;
    int combined;
    int *p;
    int aa;
    int bb;
    int d1;
    int d2;

    sub_0800A040();
    CpuFastSet((void *)0x05000000, gUnknown_030049D4, size = 256);
    combined = a | (a << 16);
    CpuFastSet(&combined, gUnknown_03002F30, 0x01000100);
    gUnknown_03002F2C = 1;
    gUnknown_030049D0 = 1;
    x = gUnknown_030049EC;
    sub_0800A404(0, size, x, x, 1, gUnknown_03002F30);
    x = gUnknown_030049EC;
    sub_0800A404(0, size, x, x, 5, (char *)gUnknown_03002F30 + 0x200);
    n = gUnknown_030049EC;
    while (n >= 0) {
        sub_080188B8();
        n--;
    }
    do {
        sub_080125F8();
        p = gUnknown_030034A4;
        aa = p[7];
        bb = p[8];
        d1 = aa - bb;
        d2 = bb - aa;
        if (d1 >= 0)
            d2 = d1;
    } while ((unsigned int)d2 < gUnknown_03006B18);
}
