struct S {
    int unk0;
    int unk4;
    int unk8;
    unsigned char unkC[3];
    unsigned char unkF;
};

extern int gUnknown_03006B14;
extern int gUnknown_030072EC;
extern struct S gUnknown_0300701C[];
extern void sub_0803F5F4(struct S *p);

void sub_0803F378(void)
{
    int i;

    if (gUnknown_03006B14 & 8)
        return;
    i = gUnknown_030072EC;
    i--;
    if (i < 0)
        return;
    do {
        if (gUnknown_0300701C[i].unkF == 1)
            sub_0803F5F4(&gUnknown_0300701C[i]);
        i--;
    } while (i >= 0);
}
