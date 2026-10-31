extern unsigned char gUnknown_0300332C[];
extern unsigned char gUnknown_03006B1C[];

void sub_0800F8EC(void)
{
    unsigned char *base = gUnknown_0300332C;
    unsigned char index = base[0xB9];
    unsigned char *slot = base + index * 0x7C;
    unsigned int obj = *(unsigned int *)slot;
    unsigned char *b = gUnknown_03006B1C;
    unsigned short v;
    if (b[0x293] != b[0x294])
        v = *(unsigned short *)(obj + 0xD8);
    else
        v = 0;
    *(unsigned short *)(slot + 0xC) = v;
}
