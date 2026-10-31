struct unk {
    unsigned char pad0[0x58];
    unsigned int unk58;
    unsigned char pad5c[0x80];
    unsigned short unk_dc;
    unsigned char padde[4];
    unsigned char unk0e2;
};

void sub_0802AF4C(void *arg0);
void sub_080020FC(struct unk *obj, int val);
void sub_08000F24(void *p);
void *sub_0800178C(void);
void sub_08002138(void *a, unsigned int b);
int sub_08017400(int a, int b);
void sub_08036AF0(unsigned int a, unsigned int b);
void sub_0803ABE0(struct unk *p);

void sub_08032A50(struct unk *p)
{
    switch ((unsigned int)p->unk0e2) {
    case 0:
        sub_0802AF4C(p);
        sub_080020FC(p, 0x4a);
        p->unk_dc = sub_08017400(10, 20);
        p->unk58 &= 0xFFFBFFFF;
        sub_08000F24(p);
        break;
    case 0x4a:
        if (--p->unk_dc == 0) {
            sub_08002138(sub_0800178C(), 0x16);
            sub_080020FC(p, 0x4b);
            p->unk_dc = sub_08017400(0x32, 0x32);
        }
        break;
    case 0x4b:
        if (--p->unk_dc == 0) {
            sub_080020FC(p, 0x4c);
            p->unk_dc = 10;
        }
        break;
    case 0x4c:
        if (--p->unk_dc == 0) {
            p->unk58 &= ~0x40;
            sub_08036AF0((unsigned int)p, 0);
        }
        break;
    default:
        sub_0803ABE0(p);
        break;
    }
}
