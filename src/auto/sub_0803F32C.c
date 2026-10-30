struct S { int unk0; int unk4; int unk8; int unkC; };
extern struct S gUnknown_0300701C[];
extern int gUnknown_030072EC;
void sub_0803F32C(void)
{
    int i = gUnknown_030072EC;
    i--;
    if (i >= 0) {
        do {
            gUnknown_0300701C[i].unk4 |= 0x80;
            i--;
        } while (i >= 0);
    }
}
