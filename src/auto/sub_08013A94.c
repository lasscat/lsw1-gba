struct Ent
{
    struct Ent *f0;
    struct Ent *f4;
    int unk8;
    int unkC;
};

extern struct Ent gUnknown_03003678[];

void sub_08013A94(struct Ent *a, int b)
{
    if (a->f4 != 0)
    {
        a->f4->f0 = a->f0;
    }
    else
    {
        gUnknown_03003678[b].f0 = a->f0;
    }
    if (a->f0 != 0)
    {
        a->f0->f4 = a->f4;
    }
}
