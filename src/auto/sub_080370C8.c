extern unsigned char gUnknown_03006B1C[];
extern void sub_080020FC(struct unk *obj, int val);
extern int sub_08017400(int a, int b);

struct unk {
    unsigned char pad0[0xE1];
    unsigned char field_E1;
    unsigned char pad1[0x11C - 0xE2];
    unsigned short field_11C;
};

void sub_080370C8(struct unk *obj)
{
    int v;
    unsigned char *p;
    obj->field_E1 = 45;
    sub_080020FC(obj, 0);
    v = sub_08017400(10, 30);
    obj->field_11C = v;
    p = gUnknown_03006B1C;
    p += 0x46C;
    if (*(unsigned int *)p & 0x01000000)
        obj->field_11C = (unsigned short)v >> 1;
}
