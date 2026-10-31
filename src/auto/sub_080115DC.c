void sub_080013F4(void *arg0, unsigned int arg1, unsigned char arg2, void *arg3);
int sub_08011528(void *arg0, void *arg1);
extern unsigned char gUnknown_0804FB00[];

void sub_080115DC(void *obj, void *arg1)
{
    void *r4 = obj;
    unsigned char *tbl;
    unsigned char b;
    unsigned int idx;
    int v;
    if (*(short *)(r4 + 0xd8) > 0 && sub_08011528(r4, arg1) != 0) {
        *(short *)(r4 + 0xdc) = 10;
        tbl = gUnknown_0804FB00;
        b = *(unsigned char *)(r4 + 0xe0);
        idx = b * 48;
        tbl += 12;
        v = -*(int *)(tbl + idx);
        *(int *)(r4 + 8) = v;
        sub_080013F4(r4 + 0x24, 0, *(unsigned char *)(r4 + 0x5f), (void *)v);
    }
}
