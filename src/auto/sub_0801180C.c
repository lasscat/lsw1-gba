extern unsigned int gUnknown_03003424;
extern unsigned int gUnknown_0300342C;
extern unsigned int gUnknown_03003428;

int sub_0801180C(int *a0)
{
    int *p;
    int v;

    gUnknown_03003424 = (unsigned int)a0;
    p = a0;
    v = *p++;
    gUnknown_0300342C = (unsigned int)p;
    gUnknown_03003428 = (unsigned int)a0 + v;
    return 0;
}
