extern void *sub_0800E81C(int, int);
extern int sub_0800E8B0(void *);

void sub_0800E534(int a, int b)
{
    unsigned char *p = sub_0800E81C(a, b);
    p[3] &= 0xFE;
    if (p[1] != 0) {
        p[1]++;
        p[2] = sub_0800E8B0(p);
        if (p[2] == 0xFF) {
            p[1] = 0;
            p[2] = sub_0800E8B0(p);
        }
    }
}
