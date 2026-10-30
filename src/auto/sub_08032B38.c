struct unk {
    unsigned char pad0[0x64];
    struct unk *unk64;
    unsigned char pad68[0x70];
    short unk_d8;
    unsigned char pad_da[2];
    unsigned short unk_dc;
    unsigned char pad_de[4];
    unsigned char unk0e2;
};

void sub_080020FC(struct unk *obj, int val);
void sub_08000F24(void *p);
void sub_080368D4(struct unk *p);
void sub_08036AF0(unsigned int a, unsigned int b);
void sub_0803ABE0(struct unk *p);

void sub_08032B38(struct unk *p)
{
    switch ((unsigned int)p->unk0e2) {
    case 0:
        sub_080020FC(p, 0x3d);
        sub_08000F24(p);
        break;
    case 0x3d:
        if (p->unk64->unk0e2 != 0x3d)
            sub_080020FC(p, 2);
        break;
    case 0x1b:
        p->unk_dc--;
        if (p->unk_dc == 0 && p->unk_d8 != 0)
            sub_08036AF0((unsigned int)p, 0);
        break;
    case 9:
        sub_080368D4(p);
        break;
    default:
        sub_0803ABE0(p);
        break;
    }
}
