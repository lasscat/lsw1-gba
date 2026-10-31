extern unsigned char gUnknown_03006B1C[];

int sub_08040C00(int a);

struct Sub413D4Entry {
    unsigned char unk0[4];
    unsigned short unk4;
    unsigned short unk6;
    unsigned short unk8;
    unsigned char unkA[78];
};

void sub_080413D4(void)
{
    unsigned char *base;
    struct Sub413D4Entry *p;
    int v;

    base = gUnknown_03006B1C;
    if (base[0x28B] > 1)
        return;
    v = sub_08040C00(2);
    if (v != -1) {
        unsigned char *a;
        int off = v * 0x58;

        a = base + 0x18;
        p = (struct Sub413D4Entry *)(a + off);
        p->unk6 = *(unsigned short *)(base + 0x3B0);
        p->unk8 = 2;
    } else {
        p = (struct Sub413D4Entry *)(base - 0x40);
        p->unk6 = *(unsigned short *)(base + 0x3B0);
        p->unk4 = *(unsigned short *)(base + 0x3B0);
        p->unk8 = 0;
    }
}
