extern unsigned int gUnknown_0804EC84[];

void sub_08000FF4(void *arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
void sub_080294FC(void *arg0);

typedef struct Obj Obj;
struct Obj {
    unsigned char _00[0x60];
    void (*state)(void *arg0);
    unsigned char _64[0xDC - 0x64];
    unsigned short timer;
};

void sub_0802949C(Obj *obj)
{
    if (obj->timer == 0) {
        sub_08000FF4(obj, gUnknown_0804EC84[0x99], gUnknown_0804EC84[0x9A] + 3, 10);
        obj->state = sub_080294FC;
        obj->timer = 11;
    } else {
        obj->timer--;
    }
}
