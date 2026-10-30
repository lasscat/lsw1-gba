extern void sub_08000D7C(void *r0, int r1, int r2);
extern unsigned char *gUnknown_030069D8;

void sub_080215FC(void *r0, int r1, int r2, int r3)
{
    sub_08000D7C(r0, r1, r2);
    *(unsigned int *)(gUnknown_030069D8 + 0x70) += r3;
}
