extern void sub_0800BF14(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
extern unsigned char gUnknown_03006B1C[];
static inline unsigned char *shifted(unsigned char *b)
{
    return b + 0x2AA;
}
void sub_0800BE68(void *arg0)
{
    unsigned char *p = arg0;
    unsigned char *b = gUnknown_03006B1C;
    sub_0800BF14(shifted(b)[p[4]], p[5], p[6], p[7], p[8], p[9], p[0xA]);
}
