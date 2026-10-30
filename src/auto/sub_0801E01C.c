extern unsigned int gUnknown_0300673C;
extern unsigned char gUnknown_030067B0[];

void sub_0801E2E0(void);
void sub_08013828(void *, int, int);

void sub_0801E01C(int arg0, int arg1)
{
    while (gUnknown_0300673C != 0)
        ;
    sub_0801E2E0();
    sub_08013828(gUnknown_030067B0, arg0, arg1 << 4);
    gUnknown_0300673C = 1;
}
