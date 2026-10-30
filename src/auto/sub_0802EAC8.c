extern unsigned char gUnknown_03006B1C[];

struct Unknown_0802EAC8
{
    unsigned char field_00[0x58];
    unsigned int field_58;
    unsigned char field_5C[0x60];
    unsigned short field_BC;
    unsigned char field_BE[0x1E];
    unsigned short field_DC;
    unsigned char field_DE[0x19];
    unsigned char field_F7;
};

void sub_0802EAC8(struct Unknown_0802EAC8 *p)
{
    gUnknown_03006B1C[0x461]++;
    if (p->field_F7 != 0)
        p->field_F7--;
    p->field_DC--;
    if (p->field_DC == 0)
        p->field_58 |= 2;
    else if (p->field_DC <= 0x32)
        p->field_BC |= 0x20;
}
