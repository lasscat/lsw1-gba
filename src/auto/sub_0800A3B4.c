extern int sub_0800A404(int a0, int a1, int a2, int a3, int a4, void *a5);

struct Row20 {
    int f0;
    int f4;
    unsigned char f8;
    unsigned char f9[11];
};
extern struct Row20 gUnknown_03002FA0[];

struct SubA3B4 {
    void *ptr;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
};

int sub_0800A3B4(struct SubA3B4 *p, int a, int b)
{
    int r = sub_0800A404(p->b4, p->b5, p->b6, p->b7, a, p->ptr);
    struct Row20 *q = &gUnknown_03002FA0[r];
    q->f8 = (unsigned char)b;
    return r;
}
