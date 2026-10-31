struct S4C7A8 {
    int v0;
    int u04[4];
};

struct S5D6CC {
    char pad[0x18];
    int f18;
    int *f1c;
    char rest[0x168 - 0x20];
};

struct S720 {
    char pad[0x3c];
    void *u3c;
};

struct SObj {
    char pad[0x58];
    int u58;
};

extern struct S4C7A8 gUnknown_0804C7A8[];
extern struct S5D6CC gUnknown_0805D6CC[];
extern int gUnknown_08057878[];
extern int gUnknown_0300368C[];
extern struct S720 *gUnknown_030072F0;

void *sub_0802D28C(int arg0, int arg1, int arg2, int arg3);
void sub_08000C7C(void *arg0, int arg1, void *arg2, int arg3);
void sub_08009F98(int a, int b, int c);

void sub_0803FB74(void)
{
    int v;
    int p;
    void *q;
    void *obj;

    v = gUnknown_0804C7A8[gUnknown_0300368C[1]].v0;
    p = gUnknown_0805D6CC[v].f18 + 0x40;
    q = (void *)*gUnknown_0805D6CC[v].f1c;
    obj = sub_0802D28C(0x46, 0x89, p, 1);
    gUnknown_030072F0->u3c = obj;
    sub_08000C7C(obj, p, q, 0);
    ((struct SObj *)gUnknown_030072F0->u3c)->u58 |= 0x10;
    sub_08009F98(gUnknown_08057878[v], 0x10, 0x10);
}
