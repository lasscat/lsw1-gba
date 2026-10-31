void sub_080393C4(int, unsigned char);
void sub_0802E70C(int a, int b, int c, int d, int e, int f);
void sub_08033374(int a, int b);

void sub_08009C00(unsigned char *a, unsigned char *b)
{
    unsigned char r5;
    int off;

    if (b[0x5c] != 0xb)
        return;
    sub_080393C4((int)a, 0xe);
    off = 0x8c;
    off = off << 1;
    r5 = a[off];
    sub_0802E70C(r5, *(int *)(a + 0xc), *(int *)(a + 0x10), 0, 0, 1);
    sub_08033374((int)a, 0x12);
    *(int *)(a + 0x58) |= 2;
}
