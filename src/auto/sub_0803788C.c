extern void sub_08004458(int a, int b);

void sub_0803788C(unsigned char *p)
{
    if (p[0xe0] == 0x5c)
        return;
    sub_08004458(p[0x104], p[0x103]);
    p[0x104] = 0;
    p[0x103] = 0;
}
