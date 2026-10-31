extern unsigned char gUnknown_03006B1C[];
extern int sub_0801419C(int x, int y);
extern void sub_080393C4(void *obj, unsigned char count);
extern void sub_0802EAC8(void *obj);

typedef void (*ObjCallback)(void *);

struct Obj2E9E8 {
    unsigned char field00[0x0C];
    int field0C;
    int field10;
    unsigned char field14[0x10];
    int field24;
    int field28;
    unsigned char field2C[0x14];
    int field40;
    int field44;
    unsigned char field48[0x10];
    unsigned int field58;
    unsigned char field5C[4];
    ObjCallback field60;
    unsigned char field64[0x58];
    unsigned short fieldBC;
    unsigned char fieldBE[0x16];
    unsigned int fieldD4;
    unsigned char fieldD8[4];
    unsigned short fieldDC;
    unsigned char fieldDE[0x19];
    unsigned char fieldF7;
};

void sub_0802E9E8(struct Obj2E9E8 *o)
{
    if (o->field24 == 0 && o->field28 == 0 && o->field44 == 0
        && (o->fieldD4 & 0x08000000) == 0
        && sub_0801419C(o->field0C, o->field10) == o->field40) {
        o->fieldD4 |= 0x80;
        o->field60 = sub_0802EAC8;
    }
    gUnknown_03006B1C[0x461]++;
    if (o->fieldF7 != 0)
        o->fieldF7--;
    o->fieldDC--;
    if (o->fieldDC == 0)
        o->field58 |= 2;
    else {
        if ((o->fieldD4 & 0x08000000) != 0 && gUnknown_03006B1C[0x45D] == 0) {
            sub_080393C4(o, 7);
            gUnknown_03006B1C[0x45D] = 5;
        }
        if (o->fieldDC <= 0x32)
            o->fieldBC |= 0x20;
    }
}
