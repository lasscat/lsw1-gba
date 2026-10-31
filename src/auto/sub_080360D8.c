struct Obj {
    unsigned char pad0[0x5F];
    unsigned char f5F;
    unsigned char pad1[0xE1 - 0x60];
    unsigned char fE1;
    unsigned char pad2[0xF2 - 0xE2];
    unsigned short fF2;
    unsigned char pad3[0x11C - 0xF4];
    unsigned short f11C;
    unsigned char f11E;
};

extern int sub_08017400(int a, int b);
extern void sub_080020FC(struct Obj *obj, int val);

void sub_080360D8(struct Obj *obj)
{
    int a;
    int b;
    obj->f5F = sub_08017400(0, 0xFF);
    if ((obj->fF2 & 7) == 3) {
        a = 10;
        b = 50;
    } else {
        b = 1000;
        a = 100;
    }
    obj->f11C = sub_08017400(a, b);
    obj->fE1 = 0x2E;
    sub_080020FC(obj, 0);
}
