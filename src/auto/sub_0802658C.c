extern int gUnknown_0300368C[];
extern unsigned char gUnknown_08E2B01C[];
extern void sub_08005870(int, int, int, int, int, int);
extern int sub_08005B3C(int, void *, unsigned short, unsigned short, int, int);
extern void sub_08006988(int, int, int);
extern void sub_0800EABC(int, int, int, int);
extern void sub_08026634(void);

void sub_0802658C(void)
{
    gUnknown_0300368C[2] = 0;
    sub_08005870(0, 0, 0, 0x20, 0x40, 0);
    sub_08005870(1, 0, 0, 0x20, 0x40, 0);
    sub_08005870(2, 0, 0, 0x20, 0x40, 0);
    sub_08006988(0, 0, 0);
    sub_08006988(1, 0, 0);
    sub_08006988(2, 0, 0);
    sub_08005B3C(1, gUnknown_08E2B01C, 10, 0, 0, 0);
    sub_0800EABC(0, 9, 0, -1);
    sub_08026634();
}
