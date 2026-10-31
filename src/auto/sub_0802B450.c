void sub_0802E70C(int a, int b, int c, int d, int e, int f);
void sub_0802F31C(unsigned char *p);

void sub_0802B450(unsigned char *p)
{
    if (p[0x101] != 0) {
        if (p[0x100] == 0)
            sub_0802F31C(p);
    }
    if (p[0x100] != 0)
        sub_0802E70C(p[0x100], *(int *)(p + 0xc), *(int *)(p + 0x10), 1, 1, 1);
}
