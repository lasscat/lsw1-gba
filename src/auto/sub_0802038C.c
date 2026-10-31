void CpuSet(const void *src, void *dest, unsigned int count);
extern void sub_080053D4(unsigned int, unsigned int);
extern void sub_0800554C(unsigned short);
extern void sub_08005648(unsigned short);
extern int sub_08005AE8(int, void *, unsigned short, unsigned short, int, int);
extern void sub_080187F8(unsigned short, int);
extern void sub_0801E224(void);
extern void sub_080204CC(void);
extern unsigned int gUnknown_030069B8[];
extern unsigned int gUnknown_0300368C[];

void sub_0802038C(void)
{
    unsigned short v;
    unsigned short *p;

    sub_0801E224();
    p = &v;
    *p = 0;
    CpuSet(&v, (void *)(0xC0 << 19), 0x01008000);
    sub_0800554C(1);
    sub_08005648(0x80 << 5);
    sub_080053D4(1, *(unsigned int *)0x0804C924);
    sub_08005AE8(0, (void *)0x08E195C4, 0, 0, 0, 0);
    gUnknown_030069B8[1] = 0;
    gUnknown_030069B8[0] = 0;
    sub_080204CC();
    gUnknown_0300368C[4] = 0;
    sub_080187F8(0x3F, 2);
}
