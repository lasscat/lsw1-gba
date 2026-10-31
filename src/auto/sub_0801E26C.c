extern unsigned char gUnknown_03006740[];
extern int gUnknown_03006738;

void sub_0801E26C(void)
{
    unsigned char *a = gUnknown_03006740;
    int *b = &gUnknown_03006738;
    int off = *b * 16;
    unsigned char *c = a + 12;
    void (**fpp)(void *, void *) = (void (**)(void *, void *))(c + off);
    unsigned char *p1 = a + 4;
    unsigned char *q1 = p1 + off;
    unsigned char *p2 = a + 8;
    unsigned char *q2 = p2 + off;
    int i;

    (*fpp)(q1, q2);
    i = *b + 1;
    *b = i;
    off = i * 16;
    if (*(int *)(c + off) != 0) {
        *(volatile unsigned short *)0x04000004 = *(volatile unsigned short *)0x04000004 & 0xFF;
        *(volatile unsigned short *)0x04000004 |= a[off] << 8;
    }
}
