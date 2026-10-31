extern unsigned int gUnknown_03006B14;
extern unsigned char gUnknown_030024EC[];
extern unsigned char gUnknown_03006B1C[];
extern void sub_080004C0(void *);
extern void sub_08000560(void);
extern void sub_080040C8(void);
extern void sub_08004380(void);
extern void sub_0800E6A8(void);
extern void sub_08014098(void);
extern void sub_08015640(int);
extern void sub_0801603C(void);
extern void sub_0801607C(void);
extern void sub_0801B0C8(void);
extern void sub_0801C2CC(void);
extern void sub_0803F2F0(void);

void sub_08024BFC(void)
{
    if (gUnknown_03006B14 & 8)
    {
        gUnknown_03006B14 &= ~8;
        sub_080004C0(gUnknown_030024EC);
        sub_08000560();
        sub_080004C0(gUnknown_030024EC);
        sub_08004380();
        sub_0801B0C8();
        sub_0801603C();
        sub_0801607C();
        sub_0801C2CC();
        sub_0800E6A8();
        sub_08014098();
        sub_08015640(0);
        sub_08015640(1);
        sub_08015640(2);
        sub_08015640(3);
        sub_08015640(4);
        if (gUnknown_03006B1C[0x293] == 0x23 || gUnknown_03006B1C[0x293] == 0x2B)
            sub_08015640(5);
        sub_080040C8();
        sub_0803F2F0();
    }
    gUnknown_03006B14 &= 0xE3FFFFFF;
    gUnknown_03006B14 &= 0xFFF7FFFF;
    gUnknown_03006B14 &= 0xBFFFFFFF;
}
