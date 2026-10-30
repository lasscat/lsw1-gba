extern unsigned int gUnknown_03003250;

void sub_0800EA04(int a, int b, int c)
{
    unsigned int *r3 = &gUnknown_03003250;
    r3[7] = a;
    r3[8] = a;
    r3[9] = b;
    r3[10] = (c + 1) << 5;
    r3[11] = c;
}
