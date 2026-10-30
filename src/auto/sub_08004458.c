extern int sub_0800499C(unsigned char);
extern void sub_080044A8(unsigned char, unsigned int);
extern void sub_080045D8(unsigned char, unsigned int);

void sub_08004458(unsigned char a, unsigned char b)
{
    if (sub_0800499C(a) != 0)
        sub_080044A8(a, 0);
    if (sub_0800499C(b) != 0)
        sub_080045D8(b, 0);
}
