extern unsigned char gUnknown_03002BC8[];
void sub_080054F4(unsigned char);
void sub_0801C19C(unsigned int);
unsigned int sub_0801C46C(unsigned int);

void sub_08004228(void)
{
    unsigned char *p = gUnknown_03002BC8;
    *(unsigned short *)&p[0xA] &= 0xFFF0;
    if (sub_0801C46C(*(unsigned int *)&p[4]) != 0)
        sub_0801C19C(*(unsigned int *)&p[4]);
    sub_080054F4(3);
}
