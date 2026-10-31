extern void sub_080137A0(void *arg0, int arg1, int arg2);
extern unsigned char gUnknown_03004980[];

void sub_08017948(void)
{
    unsigned char *base = gUnknown_03004980;
    sub_080137A0(*(void **)(base + 0x10), 0, 0xa0);
}

