typedef void (*Func)(void);

struct S125B4 {
    int unk0;
    int unk4;
    Func fn;
};

extern struct S125B4 *gUnknown_030034A4;

void sub_08012A3C(void);

void sub_080125B4(Func f)
{
    if (f == 0)
        gUnknown_030034A4->fn = sub_08012A3C;
    else
        gUnknown_030034A4->fn = f;
}
