extern unsigned char gUnknown_03002EC4[];
extern unsigned int gUnknown_03002F24;

void sub_0800A160(unsigned char r0)
{
    unsigned char *r1 = (unsigned char *)(gUnknown_03002EC4 + (r0 << 3));
    unsigned char r3 = *r1;
    r3 |= 1;
    *r1 = r3;
    gUnknown_03002F24 |= (1 << r0);
}
