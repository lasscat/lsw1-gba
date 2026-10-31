extern void sub_08010BE4(void *arg0, int arg1, int arg2);
void sub_08033374(int a, int b);

void sub_08042C28(void *arg0, void *arg1)
{
    unsigned char *p = (unsigned char *)arg1;
    unsigned char *q = (unsigned char *)arg0;
    unsigned int v;
    if (p[0x5c] != 1) {
        return;
    }
    sub_08033374(arg0, 0x34);
    sub_08010BE4(arg1, q[0xf4] >> 1, q[0xf5]);
    v = *(unsigned int *)((char *)arg0 + 0x58);
    v |= 2;
    v &= ~1;
    *(unsigned int *)((char *)arg0 + 0x58) = v;
}
