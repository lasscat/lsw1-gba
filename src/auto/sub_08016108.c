extern void sub_08012C28(void *, void *, void *);
extern char gUnknown_03004934[];

void sub_08016108(void *arg0)
{
    void *r4;
    void *r2 = arg0;
    void *r0 = gUnknown_03004934;
    r4 = r0 - 0x14;
    sub_08012C28(r0, r4, r2);
    *(unsigned short *)(r4 + 0x20) -= 1;
}
