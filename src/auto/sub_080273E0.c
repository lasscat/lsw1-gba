extern unsigned char gUnknown_03006B1C[];
extern unsigned int gUnknown_03006AF0[];
extern unsigned int gUnknown_03004980[];

void sub_0802C428(void);
void sub_0802C910(void);
void sub_08017BC4(void);
void sub_0802C960(void);

void sub_080273E0(void)
{
    unsigned int *dst;
    sub_0802C428();
    gUnknown_03006B1C[0x280] = 0x80;
    gUnknown_03006B1C[0x281] = 0x80;
    sub_0802C910();
    dst = gUnknown_03004980;
    {
        signed char x = *(signed char *)(gUnknown_03006AF0[0] + 0x30);
        dst[14] = (unsigned int)x;
    }
    sub_08017BC4();
    sub_0802C960();
    gUnknown_03006B1C[0x444] = 1;
}
