struct Sub0801EE48Inner {
    unsigned short unk0;
    unsigned short unk2;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
};

struct Sub0801EE48Outer {
    int unk0;
    struct Sub0801EE48Inner inners[2];
};

extern struct Sub0801EE48Outer gUnknown_03006924[];

extern int sub_0801346C(int a, int b);

void sub_0801EE48(int a)
{
    struct Sub0801EE48Outer *o = &gUnknown_03006924[a];
    struct Sub0801EE48Inner *p;
    unsigned int i;
    for (i = 0, p = &o->inners[0]; i <= 1; p++, i++) {
        if ((p->unk0 & 2) == 0)
            continue;
        if (p->unk2 != 0) {
            if (p->unk2 > 1) {
                p->unk4 += sub_0801346C(p->unk14 - p->unk4, p->unk2);
                p->unk8 += sub_0801346C(p->unk18 - p->unk8, p->unk2);
            } else {
                p->unk4 = p->unk14;
                p->unk8 = p->unk18;
                p->unk0 &= 0xFFFD;
            }
            p->unk2--;
        } else {
            p->unk4 += p->unkC;
            p->unk8 += p->unk10;
        }
        o->unk0 |= 1;
    }
}
