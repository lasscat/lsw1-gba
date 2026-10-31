extern void sub_0800A8B0(void *);
extern unsigned char gUnknown_03006AD4[];
extern unsigned char gUnknown_03004980[];
extern unsigned int gUnknown_03006B14;

void sub_08025A00(void)
{
    if (gUnknown_03006AD4[2] == 0) {
        gUnknown_03004980[0xD] &= 0x7F;
        sub_0800A8B0((void *)0x080481E4);
    } else {
        unsigned char *q = gUnknown_03004980;
        q[0xD] |= 0x80;
        sub_0800A8B0((void *)0x08048204);
    }
    gUnknown_03006B14 |= 0x40;
}
