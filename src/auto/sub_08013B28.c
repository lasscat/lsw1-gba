struct S {
    void *unk0;
    void *unk4;
    void *unk8;
    void *unkC;
};

void sub_08013B28(void *arg0, void *arg1)
{
    struct S *a = arg0;
    struct S *n = a->unk0;

    if (n == 0)
        return;
    if (n->unkC == (void *)-1)
        return;
    if (n->unkC != 0)
        ((struct S *)n->unkC)->unk8 = n->unk8;
    if (n->unk8 != 0)
        ((struct S *)n->unk8)->unkC = n->unkC;
    a->unk0 = n->unk0;
    if (n->unk0 != 0)
        ((struct S *)n->unk0)->unk4 = a;
}
