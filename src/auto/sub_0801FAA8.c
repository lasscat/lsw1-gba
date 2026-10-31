struct TableEntry {
    char pad[8];
    unsigned short unk8;
    unsigned short unkA;
    char pad2[8];
};

struct MainObj {
    char pad[136];
    void *ptr;
    signed char idx;
};

extern struct MainObj *gUnknown_0300699C;
extern struct TableEntry gUnknown_0804C7A8[];
extern void sub_08000D7C(void *arg0, int arg1, int arg2);
extern void sub_0801F8BC(void);

void sub_0801FAA8(void)
{
    struct MainObj *p = gUnknown_0300699C;
    void *obj = p->ptr;
    struct TableEntry *base = gUnknown_0804C7A8;
    int idx = p->idx;
    sub_08000D7C(obj, base[idx].unk8 << 16, base[idx].unkA << 16);
    sub_0801F8BC();
}
