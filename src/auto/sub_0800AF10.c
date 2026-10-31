extern unsigned int gUnknown_03003190[];

typedef struct {
    unsigned short unk_00;
    unsigned char unk_02[4];
    unsigned char unk_06;
    unsigned char unk_07[3];
    unsigned short unk_0A;
} Arg0800AF10;

void sub_0800AF10(Arg0800AF10 *a)
{
    unsigned short v;
    unsigned int t;
    unsigned int *p;
    volatile unsigned int *d;
    v = a->unk_00;
    if ((v & 2) == 0)
        return;
    a->unk_00 = v & 0xFFFD;
    t = a->unk_00 & 4;
    p = gUnknown_03003190;
    if (t != 0)
        p += 2;
    d = (volatile unsigned int *)0x040000D4;
    d[0] = p[0] + (a->unk_06 << 1);
    d[1] = p[1] + (a->unk_06 << 1);
    d[2] = 0x80000000u | a->unk_0A;
    (void)d[2];
}
