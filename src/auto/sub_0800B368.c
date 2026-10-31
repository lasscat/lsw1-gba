void sub_08004458(unsigned char a, unsigned char b);
extern unsigned int sub_0802AFC8(unsigned int a);
extern unsigned int gUnknown_03002BE8;
extern unsigned int gUnknown_030031C4;

struct Arg0800B368 {
    unsigned char pad[4];
    unsigned short unk4;
    unsigned char unk6;
    unsigned char unk7;
};

struct Ret0800B368 {
    unsigned char pad[220];
    unsigned short unkDC;
    unsigned char pad2[22];
    unsigned char unkF4;
    unsigned char unkF5;
};

void sub_0800B368(struct Arg0800B368 *p)
{
    unsigned int v = gUnknown_03002BE8;
    if (p->unk4 == 0) {
        sub_08004458(p->unk6, p->unk7);
    } else {
        struct Ret0800B368 *q;
        if (gUnknown_030031C4 == 1 && *(unsigned int *)v != 0)
            gUnknown_030031C4 = 2;
        q = (struct Ret0800B368 *)sub_0802AFC8(1);
        q->unkDC = p->unk4 * 30;
        q->unkF4 = p->unk6;
        q->unkF5 = p->unk7;
    }
}
