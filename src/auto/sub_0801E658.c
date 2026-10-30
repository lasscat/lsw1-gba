void sub_0801E84C(unsigned short a, unsigned short b);

void sub_0801E658(unsigned short a, unsigned int b, unsigned char c)
{
    unsigned int d;
    unsigned short e;

    e = a;
    if (e == 0xFFFF)
        return;
    d = b >> 6;
    if (c != 0)
        d = b >> 5;
    sub_0801E84C(e, d);
}
