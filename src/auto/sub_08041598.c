void sub_080414F4(unsigned int, void *, int);
void sub_0801BEB8(int);

struct S41598
{
    unsigned char unk0;
    unsigned char pad1[3];
    unsigned short unk4;
    unsigned short unk6;
    unsigned short unk8;
    unsigned short padA;
    unsigned int unkC;
    void *unk10;
};

void sub_08041598(struct S41598 *p)
{
    if (p->unk4 != p->unk6)
    {
        if (--p->unk8 == 0)
        {
            p->unk8 = 2;
            if (p->unk6 > p->unk4)
                p->unk4++;
            else
                p->unk4--;
            sub_080414F4(p->unk4, p->unk10, 3);
            sub_0801BEB8(4);
        }
    }
}
