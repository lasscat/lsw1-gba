typedef struct Obj {
    unsigned char pad00[8];
    int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned char pad14[0x20];
    unsigned int unk34;
    unsigned int unk38;
    unsigned char pad3C[0x1C];
    unsigned int unk58;
    unsigned char pad5C[3];
    unsigned char unk5F;
    unsigned char pad60[0x74];
    int unkD4;
    unsigned char padD8[8];
    unsigned char unkE0;
    unsigned char unkE1;
    unsigned char unkE2;
    unsigned char unkE3;
    unsigned char padE4[0x0E];
    unsigned short unkF2;
    unsigned char padF4[0x28];
    unsigned short unk11C;
} Obj;

void sub_080020FC(struct Obj *obj, int val);
void sub_08000F24(struct Obj *p);
int sub_080015E0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, int e);
extern void *sub_08033374(int a, int b);
void sub_08036AF0(unsigned int obj, unsigned int val);
void sub_0803ABE0(struct Obj *obj);

void sub_08031978(struct Obj *p)
{
    unsigned int state = p->unkE2;
    int v;
    switch (state) {
    case 0:
        sub_080020FC(p, 3);
    case 3:
        v = sub_080015E0(p->unk0C, p->unk10, p->unk34, p->unk38, p->unk08);
        if (v == 0x100 || p->unk11C == 0) {
            if (p->unkE0 == 0x54 && (p->unkF2 & 0x200) != 0) {
                sub_08000F24(p);
                sub_080020FC(p, 0x57);
            } else {
                state = 2;
            }
        } else {
            p->unk11C--;
            if (p->unk5F != v) {
                p->unk5F = v;
                p->unkE3 |= 8;
            }
        }
        break;
    case 0x57:
        if ((p->unk58 & 0x40000) == 0)
            break;
        p->unkF2 &= 0xFDFF;
        if ((p->unkD4 &= 0xBFFFFFFF) >= 0)
            sub_08033374((int)p, 0x37);
        state = 2;
        break;
    default:
        sub_0803ABE0(p);
        break;
    }
    if (state == 2)
        sub_08036AF0((unsigned int)p, 0);
}
