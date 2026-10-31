extern unsigned char gUnknown_03006B1C[];
extern unsigned int gUnknown_03006AF0[];
extern unsigned int gUnknown_03004980[];

int sub_08017EE8(int);
int sub_08017F30(int);
void sub_08017978(int);
void sub_0801BD2C(void);
void sub_0801BD50(void);
void sub_0801BEB8(int);
void sub_080274E8(int);
void sub_0802C428(void);

void sub_08027450(void)
{
    unsigned int base;
    signed char x;
    unsigned int *dst;

    base = gUnknown_03006AF0[0];
    x = *(signed char *)(base + 0x30);
    if (*(unsigned char *)(base + x) == 0) {
        sub_0801BEB8(0x11);
        return;
    }
    dst = gUnknown_03004980;
    dst[14] = (unsigned int)x;
    sub_0801BD2C();
    sub_08017F30(dst[14]);
    sub_0801BD50();
    if (sub_08017EE8(dst[14]) != 0) {
        sub_0801BEB8(1);
        sub_0802C428();
        sub_08017978(dst[14]);
        sub_080274E8(0x12);
        gUnknown_03006B1C[0x444] = 1;
    } else {
        sub_0801BEB8(0x11);
    }
}
