extern unsigned int gUnknown_03006AF0[];

void sub_08009F98(int a, int b, int c);
void *sub_0802D28C(int arg0, int arg1, int arg2, int arg3);
void sub_0800074C(void *arg0, void *arg1);
void sub_0800EABC(int a, int b, int c, int d);
void *sub_0802D408(int a, int b, int c, int d);
void sub_0802720C(void);

struct S2716C {
    int unk[3];
    void *items[3];
    int unk18[5];
    void *tail;
};

void sub_0802716C(void)
{
    unsigned int i;
    int *p;
    struct S2716C **base;
    void *obj;
    int v;

    sub_08009F98(0x08EBA390, 0x10, 0x10);
    i = 0;
    base = (struct S2716C **)gUnknown_03006AF0;
    p = (int *)0x0804EACC;
    do {
        v = *p;
        p += 3;
        obj = base[0]->items[i] = sub_0802D28C(0xBA, v - 2, 0x03000118, 1);
        sub_0800074C(obj, (void *)0x0804EAF0);
        *(int *)((char *)base[0]->items[i] + 0x58) |= 0x10;
        i++;
    } while (i <= 2);
    sub_0800EABC(0, 9, 0, 0);
    ((struct S2716C *)gUnknown_03006AF0[0])->tail = sub_0802D408(0x3B, 0x78, 5, 1);
    sub_0802720C();
}
