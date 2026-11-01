extern volatile unsigned short gUnknown_04000208;
extern volatile unsigned short gUnknown_04000200;

void sub_0801C568(void)
{
    gUnknown_04000208 = 0;
    gUnknown_04000200 = gUnknown_04000200 & 0xFFEF;
    gUnknown_04000208 = 1;
}
