struct Obj35C3C {
    unsigned char pad00[0x0C];
    int x;
    int y;
    unsigned char pad14[0x2C];
    int field40;
    unsigned char pad44[0x14];
    unsigned int field58;
    unsigned char pad5C[0x86];
    unsigned char fieldE2;
};

extern void sub_08000C7C(void *obj, void *a, void *b, int c);
extern void sub_080020FC(void *obj, int val);
extern void sub_080393C4(int obj, unsigned char val);
extern int sub_0801419C(int x, int y);
extern unsigned char gUnknown_08055F60[];
extern unsigned char gUnknown_08327F94[];

void sub_08035C3C(struct Obj35C3C *obj)
{
    switch (obj->fieldE2) {
    case 0: { int v = sub_0801419C(obj->x, obj->y) + 0x50000; if (obj->field40 <= v) sub_080020FC(obj, 10); break; }
    case 10: sub_08000C7C(obj, gUnknown_08055F60, gUnknown_08327F94, 0); sub_080020FC(obj, 2); sub_080393C4((int)obj, 0x11); break;
    case 2: if (obj->field58 & 0x40000) obj->field58 |= 2; break;
    }
}
