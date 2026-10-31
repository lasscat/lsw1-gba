extern unsigned char gUnknown_0300477C[];
extern unsigned char gUnknown_030047A0[];
extern unsigned int gUnknown_03003774;
extern void ObjAffineSet(void *src, void *dest, int num, int offset);

void sub_080153F0(void)
{
    unsigned char *p = gUnknown_0300477C;
    unsigned char *q = p + 0x22;

    if (*q == 0)
        return;
    ObjAffineSet(gUnknown_030047A0, (void *)(gUnknown_03003774 + 6), *q, 8);
    ObjAffineSet(gUnknown_030047A0, (void *)(gUnknown_03003774 + 0x406), *q, 8);
}
