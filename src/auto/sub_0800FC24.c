extern unsigned char gUnknown_0300332C[];
extern int gUnknown_08057BC0[];
extern int gUnknown_08057878[];
extern int gUnknown_08057A1C[];
extern void sub_08009F98(int a, int b, int c);

void sub_0800FC24(int arg0)
{
    if ((gUnknown_0300332C + 0xC4)[(signed char)gUnknown_0300332C[0xBF]] != 0)
        sub_08009F98(gUnknown_08057BC0[arg0 - 0x2C], 0, 0x10);
    else
        sub_08009F98(gUnknown_08057878[arg0], 0, 0x10);
    if (arg0 == 0x42)
        sub_08009F98(gUnknown_08057A1C[arg0], 0x10, 0x10);
    else
        sub_08009F98(gUnknown_08057A1C[arg0], 0x10, 8);
}
