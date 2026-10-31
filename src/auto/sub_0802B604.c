void sub_08000D00(void *arg0, int arg1);
struct S0805171C { unsigned char f[0x15]; unsigned char v; unsigned char rest[0x30 - 0x16]; };
extern struct S0805171C gUnknown_0805171C[];
void sub_0802B604(unsigned char *p)
{
    if (--p[0x94] != 0)
        return;
    if (p[0xF2] != 0) {
        if (p[0x103] != 0)
            p[0x103]--;
        else
            p[0xF0] = 0;
    } else {
        if (p[0x103] < gUnknown_0805171C[p[0xE0]].v)
            p[0x103]++;
        else
            p[0xF0] = 0;
    }
    sub_08000D00(p, p[0x103]);
    { unsigned char v = p[0x95]; p[0x94] = v; }

}
