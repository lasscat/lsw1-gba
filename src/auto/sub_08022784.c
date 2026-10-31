void sub_08000D7C(void *arg0, int arg1, int arg2);
extern int gUnknown_0804CB7C[];

struct Obj {
    int unk_00;
    int unk_04;
    int unk_08;
    int unk_0C;
};

struct Main {
    int unk_00;
    int unk_04;
    int unk_08;
    struct Obj *a;
    struct Obj *b;
    signed char idx;
};

extern struct Main *gUnknown_030069F4;

void sub_08022784(void)
{
    sub_08000D7C(gUnknown_030069F4->a, gUnknown_030069F4->a->unk_0C, (gUnknown_0804CB7C[gUnknown_030069F4->idx] + 11) << 16);
    sub_08000D7C(gUnknown_030069F4->b, gUnknown_030069F4->b->unk_0C, (gUnknown_0804CB7C[gUnknown_030069F4->idx] + 11) << 16);
}
