extern void sub_08035F20(void *obj);
extern void sub_08036DA0(void *obj);
extern void sub_080020FC(void *obj, int val);
extern void sub_080393C4(void *obj, unsigned int val);

struct Obj3660C {
    char _00[0x64];
    int f64;
    char _68[0x6C];
    unsigned int fD4;
    char _D8[8];
    unsigned char fE0;
    unsigned char fE1;
};

void sub_0803660C(struct Obj3660C *obj)
{
    if (obj->f64 == 0) {
        sub_08035F20(obj);
        return;
    }
    if (obj->fD4 & 0x04000000) {
        sub_08036DA0(obj);
        return;
    }
    obj->fD4 &= 0xFFFEFFFF;
    obj->fE1 = 0x25;
    sub_080020FC(obj, 0);
    if (obj->fE0 == 0x57)
        sub_080393C4(obj, 0x4D);
    else
        sub_080393C4(obj, 0x35);
}
