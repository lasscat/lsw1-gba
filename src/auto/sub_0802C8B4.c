extern unsigned char gUnknown_03006B1C[];
extern unsigned char gUnknown_03004980[];
void sub_0802C910(void);

void sub_0802C8B4(void)
{
    gUnknown_03006B1C[0x280] = 0x7F;
    gUnknown_03006B1C[0x281] = 0xC0;
    gUnknown_03006B1C[0x283] = gUnknown_03004980[0x0A];
    gUnknown_03006B1C[0x284] = 0;
    *(unsigned int *)(gUnknown_03006B1C + 4) = 0;
    sub_0802C910();
}
