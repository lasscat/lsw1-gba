void *sub_08000234(void);
void sub_08033458(void *a, unsigned int b, int c, int d);
void sub_080335C0(void);

void *sub_08033374(int a, int b)
{
    int x = a;
    int y = b;
    unsigned char *p = sub_08000234();
    p[0x5c] = 0x14;
    p[0xe0] = y;
    *(int *)(p + 0x68) = x;
    *(void **)(p + 0x60) = sub_080335C0;
    {
        unsigned int v = ((unsigned char *)0x08056080)[y];
        sub_08033458(p, v, 0, 1);
    }
    return p;
}
