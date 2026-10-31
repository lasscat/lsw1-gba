extern int sub_0800A9F8(int a0, int a1, int a2, int a3);

struct Ent0800A404 {
    unsigned short h0;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    unsigned char b8;
    unsigned char b9;
    unsigned short hA;
    void *pC;
    void *p10;
};

extern struct Ent0800A404 gUnknown_03002FA0[];

int sub_0800A404(int a0, int a1, int a2, int a3, int a4, void *a5)
{
    int v = sub_0800A9F8(a0, a1, a2, a3);
    struct Ent0800A404 *p = &gUnknown_03002FA0[v];
    p->h0 = (unsigned short)a4;
    p->b2 = (unsigned char)a2;
    p->b3 = (unsigned char)a2;
    p->b4 = (unsigned char)a3;
    p->b5 = (unsigned char)a3;
    p->b6 = (unsigned char)a0;
    p->b7 = (unsigned char)(a0 + a1 - 1);
    p->hA = (unsigned short)a1;
    p->b8 = 0;
    p->b9 = 0;
    p->pC = a5;
    p->p10 = a5;
    return v;
}
