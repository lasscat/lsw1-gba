extern void sub_08005408(int a, int b);
extern void sub_08005648(unsigned short a);

void sub_080053D4(unsigned int a, unsigned int b)
{
    unsigned int r4;
    unsigned int r0;
    r4 = a;
    sub_08005408(a, b);
    r0 = 0x80 << 17;
    r0 = r0 << r4;
    r0 = r0 >> 16;
    sub_08005648((unsigned short)r0);
}
