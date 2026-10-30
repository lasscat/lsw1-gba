extern unsigned char gUnknown_03006B1C[];
extern volatile unsigned char gUnknown_03006690[];

extern void sub_08046734(void);

void sub_0801C368(void)
{
    if (gUnknown_03006B1C[0x281] != 0) {
        if ((gUnknown_03006690[6] & 1) != 0) {
            sub_08046734();
            gUnknown_03006690[6] &= 0xFE;
        }
    }
}
