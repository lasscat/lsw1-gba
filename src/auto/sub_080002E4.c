void *sub_08000234(void);
void sub_08000D7C(void *arg0, int arg1, int arg2);
void sub_080156D8(void *arg0, void *arg1);

void *sub_080002E4(int arg0, int arg1, int arg2, void *arg3)
{
    void *p = sub_08000234();
    if (p == 0)
        return 0;
    sub_08000D7C(p, arg1 << 16, arg2 << 16);
    *(unsigned char *)((unsigned char *)p + 0x5c) = arg0;
    *(int *)((unsigned char *)p + 0x58) = 0x19;
    *(unsigned char *)((unsigned char *)p + 0xbf) = 0x80;
    if (arg3 != 0)
        sub_080156D8(p, arg3);
    return p;
}
