typedef struct {
    unsigned char pad00[0x0c];
    unsigned int f0c;
    unsigned int f10;
    unsigned int f14;
} Struct_0300368C;

extern Struct_0300368C gUnknown_0300368C;

typedef struct {
    unsigned char pad00[0x28];
    int f28;
    unsigned char pad2C[0x34];
    unsigned int f60;
} Elem_030069D8;

typedef struct {
    unsigned char pad00[0x28];
    char *arr[15];
    int idx;
} Struct_030069D8;

extern Struct_030069D8 *gUnknown_030069D8;

extern int sub_08021078(void);
extern char *sub_08020B40(unsigned int a);
extern void sub_08021678(void *arg0);
extern void sub_0801D47C(void *arg0, void *arg1);
extern void sub_0801D514(void *arg0, void *arg1, short arg2, short arg3, int flags);
extern void sub_080217C4(void);

void sub_080210E0(void)
{
    int v = sub_08021078();

    if (v != 0) {
        gUnknown_0300368C.f10 = 1;
        gUnknown_0300368C.f14 = 0;
    } else if (gUnknown_0300368C.f14++ > 0x10 && gUnknown_0300368C.f0c <= 0x250) {
        char *s;

        gUnknown_0300368C.f14 = v;
        s = sub_08020B40(gUnknown_0300368C.f0c);
        sub_08021678(gUnknown_030069D8->arr[gUnknown_030069D8->idx]);
        sub_0801D47C(gUnknown_030069D8->arr[gUnknown_030069D8->idx], s);
        sub_0801D514(gUnknown_030069D8->arr[gUnknown_030069D8->idx], s, 0x78, 0xA0, 1);
        ((Elem_030069D8 *)gUnknown_030069D8->arr[gUnknown_030069D8->idx])->f60 = (unsigned int)sub_080217C4;
        ((Elem_030069D8 *)gUnknown_030069D8->arr[gUnknown_030069D8->idx])->f28 = 0xFFFF8000;
        gUnknown_0300368C.f0c++;
        if (++gUnknown_030069D8->idx == 0x0d)
            gUnknown_030069D8->idx = v;
    }
}
