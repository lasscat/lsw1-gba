extern unsigned int gUnknown_03002BFC;
extern void sub_08004458(int a, int b);

void sub_08004B98(unsigned char a, unsigned char b)
{
    unsigned int base = gUnknown_03002BFC;
    unsigned int off = a * 2;
    unsigned int t = base + 2;
    unsigned short h;
    unsigned int p;
    unsigned int q;
    t += off;
    h = *(unsigned short *)t;
    p = base + h;
    q = b * 8 + 4;
    sub_08004458(0, *(unsigned char *)(p + q + 4));
}
