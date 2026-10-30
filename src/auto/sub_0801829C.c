extern void *gUnknown_030049D4;
extern void *sub_080135D0(int);
extern void sub_08018888(int, int);

void sub_0801829C(void)
{
    void *r4;
    sub_08018888(0, 8);
    r4 = gUnknown_030049D4;
    r4 = sub_080135D0(0x400);
    gUnknown_030049D4 = r4;
}
