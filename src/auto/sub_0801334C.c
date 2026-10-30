extern int sub_08043C3C_from_thumb(int a, int b);

int sub_0801334C(int a, unsigned short b)
{
    return sub_08043C3C_from_thumb(a * (unsigned int)b, 100);
}
