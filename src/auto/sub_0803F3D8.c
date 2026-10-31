struct UnkStruct_0803F504 {
    unsigned int unk0;
    unsigned int unk4;
    unsigned short unk8;
    unsigned char unkA;
    unsigned char unkB;
    unsigned char unkC;
    unsigned char unkD;
    unsigned char unkE;
    unsigned char unkF;
};

extern unsigned int gUnknown_03006B14;
extern struct UnkStruct_0803F504 gUnknown_0300701C[];
extern int gUnknown_030072EC;

void sub_0803F59C(struct UnkStruct_0803F504 *arg0);
void sub_0803F3D8(void)
{
    int i;
    struct UnkStruct_0803F504 *q;
    struct UnkStruct_0803F504 *p;

    if (gUnknown_03006B14 & 8)
        return;
    i = gUnknown_030072EC;
    i--;
    if (i < 0)
        return;
    q = gUnknown_0300701C;
    p = q + i;
    do {
        if (p->unkF == 1)
            sub_0803F59C(p);
        p--;
        i--;
    } while (i >= 0);
}
