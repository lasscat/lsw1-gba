extern int sub_0800A404(int a0, int a1, int a2, int a3, int a4, int a5);
struct S { unsigned char f0[8]; unsigned char f8; unsigned char f9[11]; };
extern struct S gUnknown_03002FA0[];
static inline struct S *elem(int v) { return &gUnknown_03002FA0[v]; }
int sub_0800A370(int a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    int v = sub_0800A404(a0, a1, a2, a3, a4, a5);
    elem(v)->f8 = (unsigned char)a6;
    return v;
}
