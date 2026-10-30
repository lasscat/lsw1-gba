extern unsigned char gUnknown_03002E14[];

void sub_080078C4(int a, int b, int c, int d)
{
    int base = (int)gUnknown_03002E14;
    int off = c * 0x54;
    int p = base + off;
    int q;
    *(int *)p = a;
    *(int *)(p + 4) = b;
    q = base + 0x38;
    q = off + q;
    *(int *)q = a;
    *(int *)(q + 4) = b;
    base = base + 0x44;
    off = off + base;
    *(int *)off = d;
}
