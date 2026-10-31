typedef struct {
    unsigned char pad00[0x58];
    unsigned int f58;
    unsigned char pad5c[0x78];
    unsigned int fD4;
} StructB;

typedef struct {
    unsigned char pad00[0x5c];
    StructB *f5c;
    unsigned char pad60[0x1c];
    unsigned char f7c;
    unsigned char f7d;
} StructA;

extern StructA *gUnknown_030069D8;
extern unsigned char gUnknown_0804CB10[];

int sub_08017400(int a, int b);
void sub_08020E14(int a);
void sub_08020E9C(void);

void sub_08020F5C(void)
{
    if (((gUnknown_030069D8->f5c->f58 & 0x40000) != 0) || ((gUnknown_030069D8->f5c->fD4 & 0x800) != 0)) {
        if (gUnknown_030069D8->f7d != 0) {
            sub_08020E9C();
        } else {
            gUnknown_030069D8->f7c--;
            if (gUnknown_030069D8->f7c == 0) {
                sub_08020E14(6);
                gUnknown_030069D8->f7d = 1;
            } else {
                sub_08020E14(gUnknown_0804CB10[sub_08017400(0, 2)]);
            }
        }
    }
}
