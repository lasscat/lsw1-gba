extern unsigned char gUnknown_030033EC[];
extern unsigned int gUnknown_03006A00[];
extern unsigned char gUnknown_03006B1C[];
void *sub_08013828(void *dst, void *src, unsigned int n);
typedef unsigned int u32;
void sub_08013DEC(u32 arg0, u32 arg1, u32 arg2);
void sub_0802C140(void);
void sub_0802E610(int);

void sub_08021980(void)
{
    unsigned char b;
    sub_08013828(gUnknown_030033EC, gUnknown_030033EC + 8, 4);
    gUnknown_030033EC[-5] = 0;
    gUnknown_030033EC[-1] = 0;
    sub_0802C140();
    sub_08013DEC(5, 0, gUnknown_03006A00[4]);
    b = gUnknown_03006B1C[0x3A8];
    gUnknown_030033EC[-9] = b;
    sub_0802E610(0);
    if (gUnknown_03006B1C[0x445] != 0) {
        unsigned short t;
        t = *(unsigned short *)(gUnknown_03006B1C + 0x3C8);
        *(unsigned short *)(gUnknown_03006B1C + 0x3B0) = t;
        t = *(unsigned short *)(gUnknown_03006B1C + 0x3CC);
        *(unsigned short *)(gUnknown_03006B1C + 0x3B4) = t;
        t = *(unsigned short *)(gUnknown_03006B1C + 0x3CA);
        *(unsigned short *)(gUnknown_03006B1C + 0x3B2) = t;
    } else {
        unsigned short u;
        u = *(unsigned short *)(gUnknown_03006B1C + 0x3B6 + gUnknown_03006B1C[0x291] * 2);
        *(unsigned short *)(gUnknown_03006B1C + 0x3B0) = u;
        u = *(unsigned short *)(gUnknown_03006B1C + 0x3C2 + gUnknown_03006B1C[0x291] * 2);
        *(unsigned short *)(gUnknown_03006B1C + 0x3B4) = u;
        u = *(unsigned short *)(gUnknown_03006B1C + 0x3BC + gUnknown_03006B1C[0x291] * 2);
        *(unsigned short *)(gUnknown_03006B1C + 0x3B2) = u;
    }
}
