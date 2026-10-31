extern int sub_08017400(int a, int b);
extern void sub_08003E78(void *p, unsigned short a, int b, int c);
extern void sub_08003E38(void *p, unsigned short a, int b, int c);
extern unsigned int gUnknown_0300332C[];

void sub_08034FA8(unsigned char *p)
{
    p[0xE2] = 8;
    sub_08003E78(p, sub_08017400(0, 0xFF), 0x900, 3);
    sub_08003E38(p, sub_08017400(0, 0xFF), 0x900, 3);
    gUnknown_0300332C[0x23] |= 1;
}
