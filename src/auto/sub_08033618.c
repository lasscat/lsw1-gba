void sub_08000C7C(void *arg0, void *arg1, void *arg2, int arg3);
void sub_0800074C(void *arg0, void *arg1);
void sub_080144F4(void *arg0);
unsigned int sub_080156D8(void *arg0, unsigned int arg1);
void sub_080393C4(void *arg0, unsigned int arg1);

struct Sub {
    unsigned char unk00[12];
    int unk0C;
    int unk10;
    unsigned char unk14[44];
    int unk40;
};

struct S {
    unsigned char unk00[4];
    int unk04;
};

struct Obj {
    unsigned char unk00[12];
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned char unk1C[8];
    int unk24;
    int unk28;
    unsigned char unk2C[20];
    int unk40;
    unsigned char unk44[20];
    unsigned int unk58;
    unsigned char unk5C[12];
    struct Sub *unk68;
    unsigned char unk6C[69];
    unsigned char unkB1;
    unsigned char unkB2[3];
    unsigned char unkB5;
    unsigned char unkB6[91];
    unsigned char unk111;
    unsigned char unk112;
    unsigned char unk113;
    unsigned char unk114;
    unsigned char unk115;
};

void sub_08033618(struct Obj *obj, struct S *s, void *p, unsigned int x, unsigned int y)
{
    unsigned char *q;
    int m;
    int n;
    struct Sub *sub;
    int a;
    int b;
    unsigned char *r;
    int t;

    obj->unk58 = 0x01004019;
    q = (unsigned char *)obj + 0xB1;
    m = 0xD;
    m = -m;
    *q &= m;
    n = 0x21;
    n = -n;
    *q &= n;
    sub_080144F4(obj);
    sub = obj->unk68;
    if (sub != 0) {
        a = sub->unk0C;
        b = sub->unk10;
        obj->unk14 = a;
        obj->unk18 = b;
        obj->unk0C = a;
        obj->unk10 = b;
        obj->unk40 = sub->unk40;
    }
    if (p != 0) {
        sub_08000C7C(obj, s, p, 0);
    } else if (s->unk04 != 0) {
        sub_0800074C(obj, s);
    } else {
        obj->unk58 &= -2;
    }
    if (x <= 0xF) {
        r = (unsigned char *)obj + 0xB5;
        t = x << 4;
        *r = (*r & 0xF) | t;
    } else {
        sub_080156D8(obj, x);
    }
    obj->unk24 = 0;
    obj->unk28 = 0;
    obj->unk111 = 0xFF;
obj->unk112 = 0; obj->unk113 = 0; obj->unk114 = 0; obj->unk115 = 0;
    sub_080393C4(obj, y);
}
