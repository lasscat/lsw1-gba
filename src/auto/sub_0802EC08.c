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

void sub_0802EC08(struct Platform *o)
{
    if (o->fieldF7 != 0) {
        o->fieldF7--;
    }

    if (o->field40 <= 0 || o->fieldE1 == 1) {
        o->field58 |= 2;
    }
}
