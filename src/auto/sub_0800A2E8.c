extern unsigned char gUnknown_03002EC4[];
extern unsigned char gUnknown_03002F3C[];
extern unsigned int gUnknown_03002F28;
extern unsigned int gUnknown_03002F38;

void *memcpy(void *dst, const void *src, unsigned int n);

void sub_0800A2E8(void)
{
    memcpy(gUnknown_03002F3C, gUnknown_03002EC4, 0x60);
    gUnknown_03002F38 = gUnknown_03002F28;
}
