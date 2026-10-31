extern int sub_08017400(int a, int b);
extern int sub_08012EC8(int a, int b);
extern void sub_08009C00(void);

struct Obj351E0
{
    unsigned char unk00[0x24];
    int f24;
    int f28;
    unsigned char unk2C[0x18];
    int f44;
    unsigned char unk48[0x10];
    int f58;
    unsigned char unk5C[3];
    unsigned char f5F;
    unsigned char unk60[0x2C];
    void (*f8C)(void);
    unsigned char unk90[0x44];
    int fD4;
    unsigned char unkD8[4];
    unsigned short fDC;
    unsigned char unkDE[6];
    unsigned char fE4;
};

extern struct Pair { int x, y; } gUnknown_08047E8C[];

void sub_080351E0(struct Obj351E0 *p)
{
    int v;
    int zero = 0;
    p->fDC = 0x3c;
    p->f44 = 0x96000;
    v = sub_08017400(0, 0x1f);
    p->f24 = sub_08012EC8(gUnknown_08047E8C[v].x, 0x1e000);
    p->f28 = sub_08012EC8(gUnknown_08047E8C[v].y, 0x1e000);
    p->f5F = v;
    p->fD4 |= 0xa000;
    p->f58 |= 0x204;
    p->f5F = zero;
    p->fE4 = 3;
    p->f8C = sub_08009C00;
}
