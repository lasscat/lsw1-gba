extern unsigned char gUnknown_03006B1C[];

void sub_0800BFF8(void *arg0)
{
    unsigned char *base = gUnknown_03006B1C;
    base += 0x2AA;
    base += ((unsigned char *)arg0)[5];
    base[0] = ((unsigned char *)arg0)[4];
}
