extern void sub_080044A8(unsigned char, unsigned int);
extern int sub_0800499C(unsigned char);
extern unsigned char gUnknown_030031C8;

void sub_0800C384(unsigned char *p)
{
    if (p[5] != 0)
        gUnknown_030031C8 = p[5];
    if (sub_0800499C(p[4]) != 0)
        sub_080044A8(p[4], 0);
}
