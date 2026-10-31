extern unsigned char gUnknown_0300332C[];

typedef struct {
    unsigned char pad[224];
    unsigned char fE0;
} Obj;

typedef struct {
    unsigned int f0;
    unsigned int f4;
    unsigned int f8;
    unsigned char pad[36];
} Row;

extern Row gUnknown_0804FB00[];

unsigned int sub_080114C4(Obj *p)
{
    if (gUnknown_0300332C[208] != 0)
        return gUnknown_0804FB00[p->fE0].f8 * 2;
    return gUnknown_0804FB00[p->fE0].f8;
}
