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

extern unsigned int sub_08004A5C(unsigned char, unsigned char);
extern Entity *sub_08040664(unsigned int, int, int, int);

void sub_0800D6A0(void *arg)
{
    unsigned char *p = arg;
    unsigned int ret = sub_08004A5C(p[4], p[5]);
    Entity *e;

    if (ret == 0)
        return;
    e = sub_08040664(ret, 0, p[6], 1);
    e->field_f1 = p[0xb];
    e->field_dc = p[0xb];
    e->field_ec = p[6];
    e->field_ed = p[7];
    e->field_ee = p[8];
    e->field_ef = p[9];
    e->field_f0 = p[0xa];
    e->field_eb = 1;
    e->field_f2 = 0;
    e->field_e8 = 0;
}
