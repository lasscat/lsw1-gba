typedef struct {
    unsigned char pad_000[0xd0];
    unsigned int field_d0;
    unsigned char pad_0d4[0x08];
    unsigned short field_dc;
    unsigned char pad_0de[0x0a];
    unsigned short field_e8;
    unsigned char field_ea;
    unsigned char field_eb;
    unsigned char field_ec;
    unsigned char field_ed;
    unsigned char field_ee;
    unsigned char field_ef;
    unsigned char field_f0;
    unsigned char field_f1;
    unsigned char field_f2;
} Entity;

extern Entity *sub_08040664(unsigned int, int, int, int);

void sub_080408C0(Entity *arg0, int arg1, int arg2, int arg3, int arg4)
{
    Entity *e;

    if (arg4 == 0 && arg0->field_d0 != 0)
        return;

    e = sub_08040664((unsigned int)arg0, 0, arg1, 1);
    e->field_f1 = 0x14;
    e->field_dc = 0x14;
    e->field_ec = arg1;
    e->field_ed = arg2;
    e->field_ee = arg3;
    e->field_ef = 0x83;
    e->field_f0 = 0x83;
    e->field_eb = 1;
    e->field_f2 = 0;
    e->field_e8 = 0x15;
}
