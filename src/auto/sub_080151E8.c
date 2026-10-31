extern signed char gUnknown_0300477C[];
extern unsigned int gUnknown_03003774;

typedef struct {
    unsigned int unk0;
    unsigned int unk4;
} Ent8;

typedef struct {
    Ent8 a[128];
    Ent8 b[128];
} Tbl;

int sub_080151E8(unsigned char a1, Ent8 *a2)
{
    Tbl *p;
    if (gUnknown_0300477C[0x20] < 0)
        return -1;
    p = (Tbl *)gUnknown_03003774;
    p->a[a1] = *a2;
    p->b[a1] = *a2;
    gUnknown_0300477C[0x20]++;
    return 0;
}
