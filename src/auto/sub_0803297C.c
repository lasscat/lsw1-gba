struct unk {
    unsigned char pad0[0x58];
    unsigned int unk58;
    unsigned char pad5c[0x80];
    unsigned short unk_dc;
    unsigned char pad_de[4];
    unsigned char unk0e2;
    unsigned char pad_e3[0x16];
    unsigned char unk_f9;
};

void sub_0802AF4C(void *arg0);
void sub_080020FC(struct unk *obj, int val);
int sub_08017400(int a, int b);
void sub_08000F24(void *p);
void sub_08031434(struct unk *p, int val);
void sub_08036AF0(unsigned int a, unsigned int b);
void sub_0803ABE0(struct unk *p);

void sub_0803297C(struct unk *p)
{
    switch ((unsigned int)p->unk0e2) {
    case 0:
        sub_0802AF4C(p);
        sub_080020FC(p, 0x4a);
        p->unk_dc = sub_08017400(15, 30);
        p->unk58 &= ~0x40000;
        sub_08000F24(p);
        break;
    case 0x4a:
        p->unk_dc--;
        sub_0802AF4C(p);
        if (p->unk_dc == 0) {
            sub_080020FC(p, 0x4b);
            sub_08031434(p, 4);
            p->unk_f9 = 0;
        }
        break;
    case 0x4b:
        sub_080020FC(p, 0x4c);
        p->unk_dc = 10;
        break;
    case 0x4c:
        if (--p->unk_dc == 0)
            sub_08036AF0((unsigned int)p, 0);
        break;
    default:
        sub_0803ABE0(p);
        break;
    }
}
