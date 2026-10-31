struct unk {
    unsigned char pad0[0x58];
    unsigned int unk58;
    unsigned char pad5c[0x8];
    struct unk *unk64;
    unsigned char pad68[0x70];
    short unk_d8;
    unsigned char pad_da[2];
    unsigned short unk_dc;
    unsigned char pad_de[4];
    unsigned char unk0e2;
    unsigned char pad_e3[0x16];
    unsigned char unkf9;
};

void sub_080020FC(struct unk *obj, int val);
void sub_08000F24(void *p);
void *sub_08033374(int a, int b);
void sub_0803ABE0(struct unk *p);

void sub_08032BD0(struct unk *p)
{
    struct unk *q;
    switch ((unsigned int)p->unk0e2) {
    case 0:
        sub_080020FC(p, 0x4a);
        p->unk_dc = 10;
        p->unk58 &= 0xFFFBFFFF;
        sub_08000F24(p);
        break;
    case 0x4a:
        if (--p->unk_dc != 0)
            break;
        sub_080020FC(p, 0x4b);
        p->unk_dc = 50;
        q = (struct unk *)sub_08033374((int)p, 0x4a);
        q->unk58 &= -5;
        p->unkf9 = 0;
        break;
    case 0x4b:
        if (--p->unk_dc != 0)
            break;
        sub_080020FC(p, 0x4c);
        p->unk_dc = 10;
        break;
    case 0x4c:
        break;
    default:
        sub_0803ABE0(p);
        break;
    }
}
