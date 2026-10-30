struct S08009FE8 {
    short f0;
    short f2;
    int f4;
};

extern int gUnknown_03002F34;
extern struct S08009FE8 gUnknown_03003090[];

void sub_08009FE8(int a0, int a1, int a2, int a3)
{
    int i = gUnknown_03002F34;
    gUnknown_03003090[i].f4 = a0 + a1;
    gUnknown_03003090[i].f0 = a2;
    gUnknown_03003090[i].f2 = a3;
    gUnknown_03002F34 = i + 1;
}
