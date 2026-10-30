extern unsigned char gUnknown_03002C50[];

void sub_08006B54(int a0, int a1)
{
    int b = (int)gUnknown_03002C50;
    int t = a0 * 0x64;
    int p = t + 0x20 + b;
    *(int *)p = (a1 << 16);
    p = t + 0x18 + b;
    *(int *)p = (a1 << 16);
    *(unsigned short *)(t + b + 0x44) |= 0x8000;
}
