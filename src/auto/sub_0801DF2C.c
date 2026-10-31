extern unsigned int gUnknown_03006738;
extern unsigned int gUnknown_0300673C;
extern unsigned char gUnknown_03006740[];
extern unsigned char gUnknown_030067B0[];

void sub_0801E2E0(void);
void sub_0801E01C(int arg0, int arg1);
void sub_08013828(void *, int, int);
void sub_0801E1EC(void);

void sub_0801DF2C(void)
{
    gUnknown_03006738 = 0;
    gUnknown_0300673C = 0;
    sub_0801E2E0();
    sub_0801E01C(0x0804C78C, 1);
    sub_08013828(gUnknown_03006740, (int)gUnknown_030067B0, 0x70);
    gUnknown_0300673C = 0;
    sub_0801E1EC();
}
