extern int gUnknown_03002F34;

struct S08009F98 {
    short a;
    short b;
    int c;
};

extern struct S08009F98 gUnknown_03003090[];

void sub_08009F98(int a, int b, int c)
{
    int i = gUnknown_03002F34;
    gUnknown_03003090[i].c = a;
    gUnknown_03003090[i].a = b;
    gUnknown_03003090[i].b = c;
    gUnknown_03002F34 = i + 1;
}
