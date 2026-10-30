extern unsigned char gUnknown_03002C54[];

void sub_0800741C(int idx, int a, int b, int c)
{
    unsigned char *base = gUnknown_03002C54 + idx * 100;
    int v = a << 8;
    *(unsigned short *)(base + 0x58) = v;
    *(unsigned short *)(base + 0x5c) = b;
    *(unsigned short *)(base + 0x60) = c;
    *(unsigned short *)(base + 0x40) |= 8;
}
