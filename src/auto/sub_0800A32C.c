extern unsigned char gUnknown_03002EC4[];
extern unsigned char gUnknown_03002F3C[];
extern unsigned int gUnknown_03002F28;
extern unsigned int gUnknown_03002F38;
void *memcpy(void *, const void *, unsigned int);

void sub_0800A32C(void)
{
    memcpy(gUnknown_03002EC4, gUnknown_03002F3C, 0x60);
    gUnknown_03002F28 = gUnknown_03002F38;
}
