extern unsigned short gUnknown_030049CC;
extern void sub_0804743C(int arg0);

void sub_08018220(void)
{
    gUnknown_030049CC = *(volatile unsigned short *)0x04000004;
    *(volatile unsigned short *)0x04000202 = 0x3FFF;
    *(volatile unsigned short *)0x04000004 = 0;
    sub_0804743C(4);
}
