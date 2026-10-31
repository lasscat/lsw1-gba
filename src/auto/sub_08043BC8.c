struct Obj
{
    unsigned char unk00[0x58];
    unsigned int flags;
    unsigned char unk5C[0x7C];
    short unkD8;
    unsigned char unkDA[2];
    unsigned short unkDC;
    unsigned char unkDE[4];
    unsigned char unkE2;
    unsigned char unkE3[5];
    struct Obj *unkE8;
};

void sub_08000494(struct Obj *node);

void sub_08043BC8(struct Obj *p)
{
    struct Obj *q = p->unkE8;
    if (q != 0 && ((q->flags & 2) != 0 || p->unkE2 == 0x1A || q->unkD8 == 0))
        sub_08000494(p);
    if (p->unkE2 == 8)
        return;
    if (p->unkE2 == 0x14)
    {
        if (p->unkDC == 0)
            p->unkE2 = 8;
        p->unkDC--;
    }
}
