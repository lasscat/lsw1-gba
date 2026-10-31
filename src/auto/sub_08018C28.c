extern int gUnknown_030049D0;
extern void *gUnknown_030049D4;
extern void *gUnknown_03002F30;
extern int gUnknown_03002F2C;
extern int gUnknown_030049EC;

extern void CpuFastSet(void *src, void *dst, unsigned int mode);
extern void sub_0800A404(int a0, int a1, int a2, int a3, int a4, void *a5);

void sub_08018C28(void)
{
    gUnknown_030049D0 = 0;
    CpuFastSet(gUnknown_030049D4, gUnknown_03002F30, 0x80);
    gUnknown_03002F2C = 1;
    sub_0800A404(0, 256, gUnknown_030049EC, gUnknown_030049EC, 1, gUnknown_03002F30);
    gUnknown_03002F2C = 0;
}
