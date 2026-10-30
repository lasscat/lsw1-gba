int sub_08033374(int a, int b);
void sub_0802E70C(int a, int b, int c, int d, int e, int f);
void sub_080435B4(void *a);

void sub_08043664(unsigned char *a, unsigned char *b)
{
    if (b[0xfb] & 0x10)
        return;
    if (a[0xe0] == 1) {
        sub_08033374((int)a, 0x4d);
    }
    {
        unsigned char r5;
        if (b[0xf7] == 1) {
            r5 = a[0xe9];
            a[0xee] = 1;
        } else {
            int t;
            unsigned char val;
            r5 = a[0xe8];
            t = sub_08033374((int)a, 0x1d);
            val = a[0xea];
            {
                int off = 0x8c;
                off = off << 1;
                ((unsigned char *)t)[off] = val;
            }
        }
        if (r5 != 0) {
            sub_0802E70C(r5, *(int *)(a + 0xc), *(int *)(a + 0x10), 0, 0, 1);
        }
    }
    sub_080435B4(a);
}
