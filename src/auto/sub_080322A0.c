struct inner {
    unsigned char unk00[0x0C];
    unsigned int unk0C;
    unsigned int unk10;
};

struct unk {
    unsigned char unk00[0x0C];
    unsigned int unk0C;
    unsigned int unk10;
    unsigned char unk14[0x5F - 0x14];
    unsigned char unk5F;
    unsigned char unk60[0x64 - 0x60];
    struct inner *unk64;
    unsigned char unk68[0xE2 - 0x68];
    unsigned char unkE2;
    unsigned char unkE3[0x11C - 0xE3];
    unsigned short unk11C;
    unsigned char unk11E;
};

extern void sub_080020FC(struct unk *obj, int val);
extern int sub_08017400(int a, int b);
extern int sub_080015E0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, int e);
extern unsigned int sub_08013254(unsigned int a, unsigned int b, unsigned int c, unsigned int d);
extern void sub_08036AF0(unsigned int obj, unsigned int val);
extern void sub_0803ABE0(struct unk *obj);

void sub_080322A0(struct unk *obj)
{
    int tmp;
    unsigned int state;
    unsigned int t0, t1, ta, tb;
    if (obj->unkE2 == 0) {
        sub_080020FC(obj, 3);
        obj->unk11C = sub_08017400(100, 200);
    }
    state = obj->unkE2;
    if (state == 3) {
        ta = obj->unk64->unk10;
        tmp = sub_080015E0(obj->unk64->unk0C, ta, obj->unk0C, obj->unk10, 0);
        t0 = obj->unk0C;
        t1 = obj->unk10;
        tb = obj->unk64->unk10;
        if (sub_08013254(t0, t1, obj->unk64->unk0C, tb) > (obj->unk11E << 16))
            state = 2;
        else if (--obj->unk11C == 0xFFFF)
            state = 2;
        else if (obj->unk5F != tmp)
            obj->unk5F = tmp;
    } else {
        sub_0803ABE0(obj);
    }
    if (state == 2)
        sub_08036AF0((unsigned int)obj, 0);
}
