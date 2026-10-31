extern int gUnknown_030031C4;
extern unsigned int sub_08004A5C(unsigned char, unsigned char);
extern void sub_08002138(void *, unsigned int);
extern void sub_08002174(void *, unsigned int);
extern void sub_080020FC(void *, int);

struct Src {
    unsigned char pad[4];
    unsigned short f4;
    unsigned short f6;
    unsigned char f8;
    unsigned char f9;
    unsigned char fA;
    unsigned char fB;
};

struct Dst {
    unsigned char pad[0x58];
    unsigned int flags;
    unsigned char pad2[0xc0];
    unsigned short f11C;
    unsigned short f11E;
    unsigned char pad3[2];
    unsigned char f122;
    unsigned char f123;
};

void sub_0800B6E4(struct Src *arg)
{
    struct Dst *obj;
    if (gUnknown_030031C4 == 1)
        gUnknown_030031C4 = 2;
    obj = (struct Dst *)sub_08004A5C(arg->f8, arg->f9);
    if (obj) {
        if (gUnknown_030031C4 == 2)
            obj->flags |= (0x80 << 20);
        obj->f11C = arg->f4;
        obj->f11E = arg->f6;
        obj->f122 = arg->fA;
        obj->f123 = arg->fB;
        sub_08002138(obj, 0x14);
        sub_08002174(obj, 8);
        sub_080020FC(obj, 0);
    }
}
