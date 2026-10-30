extern unsigned char gUnknown_03006B1C[];
extern int sub_0801419C(int x, int y);
extern void sub_080393C4(void *obj, unsigned char count);
extern void sub_0802EC08(void *obj);

typedef void (*ObjCallback)(void *);

struct Platform {
    unsigned char field00[0x0C];
    int x;
    int y;
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
    unsigned char field64[0x70];
    unsigned int fieldD4;
    unsigned char fieldD8[9];
    unsigned char fieldE1;
    unsigned char fieldE2[2];
    unsigned char fieldE4;
    unsigned char fieldE5[0x12];
    unsigned char fieldF7;
};

void sub_0802EB38(struct Platform *o)
{
    if (o->field24 == 0 && o->field28 == 0) {
        o->field58 &= 0xFFFFFDFF;
        o->fieldE4 = 1;
        if (o->field44 == 0 && (o->fieldD4 & 0x08000000) == 0
            && sub_0801419C(o->x, o->y) == o->field40) {
            o->fieldD4 |= 0x80;
            o->field60 = sub_0802EC08;
        }
    }

    if (o->fieldF7 != 0) {
        o->fieldF7--;
    }

    if (o->field40 <= 0 || o->fieldE1 == 1) {
        o->field58 |= 2;
    }

    if ((o->fieldD4 & 0x08000000) != 0) {
        if (gUnknown_03006B1C[0x45D] == 0) {
            sub_080393C4(o, 7);
            gUnknown_03006B1C[0x45D] = 5;
        }
    }
}
