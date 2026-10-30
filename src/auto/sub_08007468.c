extern unsigned char gUnknown_03002C54[];

void sub_08007468(int idx, int a, int b, int c)
{
    unsigned char *base = gUnknown_03002C54 + idx * 100;
    int v = a << 8;
    *(unsigned short *)(base + 0x5a) = v;
    *(unsigned short *)(base + 0x5e) = b;
    *(unsigned short *)(base + 0x62) = c;
    *(unsigned short *)(base + 0x40) |= 8;
}
