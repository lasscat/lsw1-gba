extern unsigned char gUnknown_03002C50[];

void sub_08006BA4(int a, int b) {
    int base = (int)gUnknown_03002C50;
    int t = 0x64;
    int off = a * t;
    int *p1;
    int *p2;
    p1 = (int *)(base + (off + 0x24));
    *p1 = b << 16;
    p2 = (int *)(base + (off + 0x1c));
    *p2 = b << 16;
    *(unsigned short *)(off + base + 0x44) |= 0x8000;
}
