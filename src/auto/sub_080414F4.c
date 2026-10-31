extern unsigned int gUnknown_08071674[];

struct S414F4
{
    unsigned char unk0[4];
    unsigned int unk4;
    unsigned char unk8[6];
    unsigned char unkE;
    unsigned char unkF;
};

void sub_080414F4(unsigned int arg0, struct S414F4 *arg1, int arg2)
{
    unsigned int v = arg0;
    struct S414F4 *p = arg1;
    int i = arg2 - 1;
    unsigned int d;
    unsigned int q;

    if (i < 0)
        return;
    do {
        q = 0;
        d = gUnknown_08071674[i];
        while (v >= d)
        {
            v -= d;
            q++;
        }
        p[i].unkE = q;
        p[i].unk4 |= 0x80;
        i--;
    } while (i >= 0);
}
