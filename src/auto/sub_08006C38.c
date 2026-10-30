extern unsigned char gUnknown_03002C50[];

void sub_08006C38(int r0, unsigned short r1) {
    int r4 = (int)gUnknown_03002C50;
    int r3 = 0x64;
    r0 = r0 * r3;
    r0 += r4;
    *(unsigned short *)(r0 + 0x40) = r1;
    *(unsigned short *)(r0 + 0x44) |= 0x4000;
}
